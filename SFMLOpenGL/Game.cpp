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
	//initialise the translation vector
	for (int i = 0; i < 8; i++)
	{
		translationArray[i] = { 1.0f,1.0f,1.0f };
	}


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
	
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	glTranslatef(0, 0, -10);
	
	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		/// <summary>
		/// open gl quads points for each square of the cube
		/// </summary>
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

	for (int i = 0; i < 8; i++)
	{
		result[i] = vectorArray[i] + translationArray[i];
	}
	result[0] = vectorArray[0] + translationArray[0];
	result[1] = vectorArray[1] + translationArray[1];
	result[2] = vectorArray[2] + translationArray[2];
	result[3] = vectorArray[3] + translationArray[3];
	result[4] = vectorArray[4] + translationArray[4];
	result[5] = vectorArray[5] + translationArray[5];
	result[6] = vectorArray[6] + translationArray[6];
	result[7] = vectorArray[7] + translationArray[7];

	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(result[4].x, result[4].y, result[4].z);
		glVertex3f(result[5].x, result[5].y, result[5].z);
		glVertex3f(result[6].x, result[6].y, result[6].z);
		glVertex3f(result[7].x, result[7].y, result[7].z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(result[0].x, result[0].y, result[0].z);
		glVertex3f(result[1].x, result[1].y, result[1].z);
		glVertex3f(result[2].x, result[2].y, result[2].z);
		glVertex3f(result[3].x, result[3].y, result[3].z);

		//right face
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(result[7].x, result[7].y, result[7].z);
		glVertex3f(result[4].x, result[4].y, result[4].z);
		glVertex3f(result[0].x, result[0].y, result[0].z);
		glVertex3f(result[3].x, result[3].y, result[3].z);


		//left face
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(result[5].x, result[5].y, result[5].z);
		glVertex3f(result[6].x, result[6].y, result[6].z);
		glVertex3f(result[2].x, result[2].y, result[2].z);
		glVertex3f(result[1].x, result[1].y, result[1].z);

		//top face
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(result[4].x, result[4].y, result[4].z);
		glVertex3f(result[5].x, result[5].y, result[5].z);
		glVertex3f(result[1].x, result[1].y, result[1].z);
		glVertex3f(result[0].x, result[0].y, result[0].z);

		//bottom face
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(result[6].x, result[6].y, result[6].z);
		glVertex3f(result[7].x, result[7].y, result[7].z);
		glVertex3f(result[3].x, result[3].y, result[3].z);
		glVertex3f(result[2].x, result[2].y, result[2].z);
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
	

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
void Game::keyPresses()
{

	/// <summary>
	/// Key presses for the rotation of the cube up
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube down
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationX(-0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube left
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// Key presses for the rotation of the cube right
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::rotationZ(-0.01) * vectorArray[i]);
		}
	}
	/// <summary>
	/// key presses for the translation Up
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 8; i++)
		{
			if (translationArray[i].z >= 0)
			{
				
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,-0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation down
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 8; i++)
		{

			if (translationArray[i].z >= 0)
			{
			
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0, -0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation left
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 8; i++)
		{

			if (translationArray[i].z >= 0)
			{
				
				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation Right
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 8; i++)
		{
			if (translationArray[i].z >= 0)
			{
			
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key press for the scaling smaller
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 8; i++)
		{
			
			vectorArray[i] = (MyMatrix3::scale(0.99f) * vectorArray[i]);
		}
	}
	/// <summary>
	/// key press for the scaling bigger
	/// </summary>
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 8; i++)
		{
			vectorArray[i] = (MyMatrix3::scale(1.01f) * vectorArray[i]);
		}
	}


}

