// OG Lab 5 TrackBall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <GL\glut.h>
#include <math.h>
#include <vector>
#include <IL/il.h>
#include <IL/ilut.h>

#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ilut.lib")
#pragma comment(lib,"ilu.lib")

using namespace std;

const float degToRad = 57.2957795;

GLuint initTexture(char* name)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	GLuint buffer;
	buffer = ilutGLLoadImage((wchar_t*)name);
	return buffer;
}

int DevILInit()
{
	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	{
		fprintf(stderr, "Incorrect devil.dll version\n");
		return 0;
	}
	if (iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION)
	{
		fprintf(stderr, "Incorrect ilu.dll version\n");
		return 0;
	}
	if (ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION)
	{
		fprintf(stderr, "Incorrect ilut.dll version\n");
		return 0;
	}
	ilInit();
	iluInit();
	ilutInit();
	ilutRenderer(ILUT_OPENGL);
	return 0;
}

class GameObject
{
public:
	float x, y, z, rx, ry, rz;
	char* name;
	char* tag;

public:

	GameObject()
	{
		Position(0, 0, 0);
		Rotation(0, 0, 0);
		name = "DefaultGameObject";
		tag = "gameobject";
	}

	GameObject(char* _name, float _x, float _y, float _z, float _rx, float _ry, float _rz)
	{
		name = _name;
		tag = "gameObject";
		Position(_x, _y, _z);
		Rotation(_rx, _ry, _rz);
	}

	GameObject& operator= (const GameObject& x) { return *this; }

	void Instantiate(float _x, float _y, float _z)
	{
		Position(_x, _y, _z);
	}

	void Rotation(float _rx, float _ry, float _rz)
	{
		rx = _rx;
		ry = _ry;
		rz = _rz;
	}

	void RotateGl(float _rx, float _ry, float _rz) 
	{
		glRotated(_rx, 1, 0, 0);
		glRotated(_ry, 0, 1, 0);
		glRotated(_rz, 0, 0, 1);
	}

	void Rotate(float _rx, float _ry, float _rz) 
	{
		rx += _rx;
		ry += _ry;
		rz += _rz;
		glutPostRedisplay();
	}

	void Position(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	void Translate(float _x, float _y, float _z) {
		x += _x;
		y += _y;
		z += _z;
		glutPostRedisplay();
	}
};

interface IDrawable
{
	float r, g, b;
	GLuint texture;
	char* textureName;
	void Draw();
};

vector<GameObject*> GameObjectsList;

class Wall : public GameObject, public IDrawable
{
public:
	float xLenght, yLenght, zLenght;
public:
	Wall()
	{
		name = "wall";
		tag = "wall";
		r = 1;
		g = 1;
		b = 1;
		xLenght = 1;
		yLenght = 1;
		zLenght = 1;
		textureName = "stoneWall.jpg";
		GameObjectsList.push_back(this);
	}

	Wall(char* _name, float _x, float _y, float _z, float _rx, float _ry, float _rz, float _r, float _g, float _b, float _xLenght, float _yLenght, float _zLenght)
		: GameObject(_name, _x, _y, _z, _rx, _ry, _rz)
	{
		tag = "wall";
		r = _r;
		g = _g;
		b = _b;
		xLenght = _xLenght;
		yLenght = _yLenght;
		zLenght = _zLenght;
		textureName = "stoneWall.jpg";
		GameObjectsList.push_back(this);
	}

	void Draw() 
	{
		glPushMatrix();
		//Enable
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		//glTextGen
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		//Transformations
		glColor3d(r, g, b);
		glTranslated(x, y, z);
		RotateGl(rx, ry, rz);
		glScaled(xLenght, yLenght, zLenght);
		//Draw
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glutSolidCube(1);
		//Reverse transformation
		glColor3d(1, 1, 1);
		glScaled(-xLenght, -yLenght, -zLenght);
		RotateGl(-rx, -ry, -rz);
		glTranslated(-x, -y, -z);
		//Disable
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}
};

class Player : public GameObject, public IDrawable
{
public:
	float radius;
	GLUquadricObj *quadrObj;

public:

	Player()
	{
		name = "player";
		tag = "player";
		r = 1;
		g = 1;
		b = 1;
		radius = 1;
		quadrObj = gluNewQuadric();
		//DevILInit();
		textureName = "player.jpg";
		GameObjectsList.push_back(this);
	}

	Player(char* _name, float _x, float _y, float _z, float _rx, float _ry, float _rz, float _r, float _g, float _b, float _radius)
		: GameObject(_name, _x, _y, _z, _rx, _ry, _rz)
	{
		tag = "player";
		r = _r;
		g = _g;
		b = _b;
		radius = _radius;
		quadrObj = gluNewQuadric();
		//DevILInit();
		textureName = "player.jpg";
		GameObjectsList.push_back(this);
	}

	void Draw ()
	{
		glPushMatrix();
		//Enable
		glEnable(GL_TEXTURE_2D);
		//Transformations
		glColor3d(r, g, b);
		glTranslated(x, y, z);
		RotateGl(rx, ry, rz);
		//Draw
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		gluQuadricTexture(quadrObj, GL_TRUE);
		gluSphere(quadrObj, radius, 100, 100);
		//Reverse transformations
		RotateGl(-rx, -ry, -rz);
		glTranslated(-x, -y, -z);
		glColor3d(1, 1, 1);
		//Disable
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
	}
};

Player player("Player",
	0, 0.1, 0,
	0, 0, 0,
	1, 1, 1,
	/*0.1, 1, 0.6,*/
	0.1);

int x = 0, y = 0, z = 0;

//segment 1
Wall wall_1_1("Wall 1 1",
	-0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall wall_1_2("Wall 1 2",
	0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall floor_1_1("Floor 1 1",
	0 + x, -0.025 + y, 0 + z,
	90, 0, 0,
	1, 1, 1,
	1, 1, 0.05);

//segment 2
Wall wall_2_1("Wall 2 1",
	-0.525 + x, 0.5 + y, 0 + (z = -1),
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall wall_2_2("Wall 2 2",
	0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall floor_2_1("Floor 2 1",
	0 + x, -0.025 + y, 0 + z,
	90, 0, 0,
	1, 1, 1,
	1, 1, 0.05);

//corner 1
Wall corner_1("Corner 1",
	-0.525 + x, 0.5 + x, 0.525 + (z = -2),
	0, 90, 0,
	1, 1, 1,
	0.055, 1.01, 0.055);

//segment 3
Wall wall_3_1("Wall 3 1",
	0 + x, 0.5 + y, -0.525 + z,
	0, 0, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall wall_3_2("Wall 3 2",
	0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall floor_3_1("Floor 3 1",
	0 + x, -0.025 + y, 0 + z,
	90, 0, 0,
	1, 1, 1,
	1, 1, 0.05);

//segment 4
Wall wall_4_1("Wall 4 1",
	-0.525 + (x = -1), 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall wall_4_2("Wall 4 2",
	0 + x, 0.5 + y, 0.525 + z,
	0, 0, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall floor_4_1("Floor 4 1",
	0 + x, -0.025 + y, 0 + z,
	90, 0, 0,
	1, 1, 1,
	1, 1, 0.05);

//corner 2
Wall corner_2("Corner 2",
	0.525 + x, 0.5 + y, 0.475 + (z=-3),
	0, 0, 0,
	1, 1, 1,
	0.055, 1.01, 0.055);

//segment 5
Wall wall_5_1("Wall 5 1",
	0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall wall_5_2("Wall 5 2",
	-0.525 + x, 0.5 + y, 0 + z,
	0, 90, 0,
	1, 1, 1,
	1, 1, 0.05);
Wall floor_5_1("Floor 5 1",
	0 + x, -0.025 + y, 0 + z,
	90, 0, 0,
	1, 1, 1,
	1, 1, 0.05);

float translationX = 0, translationY = 0, translationZ = 0;
float speed = 0.005;

void Reshape(int w, int h) {
	if (h == 0) h = 1;
	float ratio = w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 0.1, 100);
	gluLookAt(0, 2, 1, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	for each (GameObject* go in GameObjectsList)
	{
		if (go->tag == "wall")
		{
			Wall* wall = (Wall*)go;
			wall->Draw();
		}
		else if (go->tag == "player")
		{
			Player* p = (Player*)go;
			p->Draw();
		}
	}
	player.Translate(translationX * speed, translationY * speed, translationZ * speed);
	player.Rotate(translationZ * speed * degToRad / 0.2,
		0,
		-translationX * speed * degToRad / 0.2);
	glTranslated(-translationX * speed, -translationY * speed, -translationZ * speed);
	glutSwapBuffers();
}

void Idle() 
{
	if (abs(translationX) > 0) { translationX -= (abs(translationX) / translationX) * speed * 2; }
	if (abs(translationX) < speed * 2) { translationX = 0; }
	if (abs(translationY) > 0) { translationY -= (abs(translationY) / translationY) * speed * 2; }
	if (abs(translationY) < speed * 2) { translationY = 0; }
	if (abs(translationZ) > 0) { translationZ -= (abs(translationZ) / translationZ) * speed * 2; }
	if (abs(translationZ) < speed * 2) { translationZ = 0; }
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w':
		translationZ = -1;
		break;
	case 's':
		translationZ = 1;
		break;
	case 'd':
		translationX = 1;
		break;
	case 'a':
		translationX = -1;
		break;
	}
	
	printf_s("key " + key);
	printf("\n");
}

int main()
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1346, 680);
	glutInitWindowPosition(10, 0);
	glutCreateWindow("3DGL");
	//glutFullScreen();
	glutIdleFunc(Idle);
	DevILInit();
	GLuint currWallTexture = 0;
	GLuint currPlayerTexture = 0;
	for each (GameObject* go in GameObjectsList)
	{
		if (go->tag == "wall")
		{
			Wall* w = (Wall*)go;
			if (currWallTexture != 0)
			{
				w->texture = currWallTexture;
			}
			else
			{
				w->texture = initTexture(w->textureName);
				currWallTexture = w->texture;
			}
		}
		else if (go->tag == "player")
		{
			Player* p = (Player*)go;
			if (currPlayerTexture != 0)
			{
				p->texture = currPlayerTexture;
			}
			else
			{
				p->texture = initTexture(p->textureName);
				currPlayerTexture = p->texture;
			}
		}
	}
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
 	//glutPassiveMotionFunc(MouseRot);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float lightPos[4] = { 1, 7, -1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glutMainLoop();
	return 0;
}

