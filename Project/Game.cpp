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

	ifstream in("Config/window.ini");

	VideoMode window_bounds(800, 600);
	string title = "None";
	unsigned framerate_limit = 120;
	bool vertival_sync_enabled = false;

	if (in.is_open()) {
		getline(in, title);
		in >> window_bounds.width >> window_bounds.height;
		in >> framerate_limit;
		in >> vertival_sync_enabled;
	}

	in.close();

	this->window = new RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertival_sync_enabled);

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
