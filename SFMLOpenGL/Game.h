#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "MyVector3.h"
#include "MyMatrix3.h"


using namespace std;
using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	void keyPresses();
	//8 vectors
	MyVector3 v1{ 1.0f, 1.0f, -1.0};
	MyVector3 v2{ -1.0f, 1.0f, -1.0 };
	MyVector3 v3{ -1.0f, -1.0f, -1.0 };
	MyVector3 v4{ 1.0f, -1.0f, -1.0f };

	MyVector3 v5{ 1.0f, 1.0f, 1.0f };
	MyVector3 v6{ -1.0f, 1.0f, 1.0f };
	MyVector3 v7{ -1.0f, -1.0f, 1.0f };
	MyVector3 v8{ 1.0f, -1.0f, 1.0f };

	//vector array to store sbove vectors
	MyVector3 vectorArray[8];
	//displacement vector
	MyVector3 displacemtVec{ 0.01f,0.01f,0 };

	//translation vector
	MyVector3 translationArray[8];
	MyVector3 result[8];
	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};