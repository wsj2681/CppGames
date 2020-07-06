#include "Game.h"

//Static Funtions



//Constructor/Destructor
CGame::CGame() {
	this->InitWindow();
}

CGame::~CGame() {
	delete this->window;
} 

//Initializer Funtions
void CGame::InitWindow()
{
	/*Create a SFML window using options from a window.ini file.*/
	this->window = new RenderWindow(VideoMode(800, 600), "C++ SFML RPG");
}

void CGame::UpdateDeltaTime()
{
	/*Update the deltatime variable with the time it takes to update and render one frame*/
	this->deltatime = this->deltaClock.restart().asSeconds();
}

void CGame::UpdateSFMLEvents()
{

		while (this->window->pollEvent(this->sfevent))
		{
			if (this->sfevent.type == Event::Closed)
				this->window->close();
		}
}

void CGame::Update()
{
	this->UpdateSFMLEvents();
}

void CGame::Render()
{

	this->window->clear();

	//Render Items;

	this->window->display();
}

void CGame::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	}
}
