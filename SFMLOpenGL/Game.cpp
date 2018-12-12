#include <Game.h>

bool updatable = false;




Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
	//vals in vector array
	vectorArray[0] = v1;
	vectorArray[1] = v2;
	vectorArray[2] = v3;
	vectorArray[3] = v4;
	vectorArray[4] = v5;
	vectorArray[5] = v6;
	vectorArray[6] = v7;
	vectorArray[7] = v8;
	glScalef(0.9f, 0.9f, 1.0f);

}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		glLoadIdentity();
	}
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vectorArray[4].x, vectorArray[4].y, vectorArray[4].z);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);
		glVertex3f(vectorArray[1].x, vectorArray[1].y, vectorArray[1].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y, vectorArray[2].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y, vectorArray[3].z);

		//right face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);
		glVertex3f(vectorArray[4].x, vectorArray[4].y , vectorArray[4].z );
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y , vectorArray[3].z );
	

		//left face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y , vectorArray[2].z );
		glVertex3f(vectorArray[1].x, vectorArray[1].y , vectorArray[1].z );

		//top face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(vectorArray[4].x, vectorArray[4].y, vectorArray[4].z);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[1].x, vectorArray[1].y, vectorArray[1].z);
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);

		//bottom face

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y, vectorArray[3].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y, vectorArray[2].z);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();
		
		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	keyPresses();
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(vectorArray[4].x, vectorArray[4].y, vectorArray[4].z);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);
		glVertex3f(vectorArray[1].x, vectorArray[1].y, vectorArray[1].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y, vectorArray[2].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y, vectorArray[3].z);

		//right face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);
		glVertex3f(vectorArray[4].x, vectorArray[4].y, vectorArray[4].z);
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y, vectorArray[3].z);


		//left face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y, vectorArray[2].z);
		glVertex3f(vectorArray[1].x, vectorArray[1].y, vectorArray[1].z);

		//top face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(vectorArray[4].x, vectorArray[4].y, vectorArray[4].z);
		glVertex3f(vectorArray[5].x, vectorArray[5].y, vectorArray[5].z);
		glVertex3f(vectorArray[1].x, vectorArray[1].y, vectorArray[1].z);
		glVertex3f(vectorArray[0].x, vectorArray[0].y, vectorArray[0].z);

		//bottom face

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(vectorArray[6].x, vectorArray[6].y, vectorArray[6].z);
		glVertex3f(vectorArray[7].x, vectorArray[7].y, vectorArray[7].z);
		glVertex3f(vectorArray[3].x, vectorArray[3].y, vectorArray[3].z);
		glVertex3f(vectorArray[2].x, vectorArray[2].y, vectorArray[2].z);
	}
	glEnd();
	glEndList();
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	
	/*glScalef(0.9f, 0.9f, 1.0f);*/
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
void Game::keyPresses()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(0.001) * vectorArray[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(-0.001) * vectorArray[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(0.001) * vectorArray[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(-0.001) * vectorArray[i]);
		}
	}



	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		/*vectorArray[i] = (MyMatrix3::translation(vectorArray[i]) * vectorArray[i]);*/
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		vectorArray[i] = (MyMatrix3::scale(-0.001) * vectorArray[i]);
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		vectorArray[i] = (MyMatrix3::scale(0.000001) * vectorArray[i]);
	//	}
	//}



}

