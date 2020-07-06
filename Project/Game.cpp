#include "Game.h"

//Static Funtions



//Constructor/Destructor
CGame::CGame() {
	this->InitWindow();
	this->InitKeys();
	this->InitStates();
}

CGame::~CGame() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop(); 
	}

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

void CGame::InitStates()
{
	this->states.push(new CGameState(this->window, &this->supportedKeys));
}

void CGame::InitKeys()
{
	this->supportedKeys.emplace("Escape", Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", Keyboard::Key::A);
	this->supportedKeys.emplace("D", Keyboard::Key::D);
	this->supportedKeys.emplace("W", Keyboard::Key::W);
	this->supportedKeys.emplace("S", Keyboard::Key::S);
}

void CGame::EndApplication()
{
	cout << "end app" << endl;
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

	if (!this->states.empty())
	{
		this->states.top()->Update(this->deltatime);

		if (this->states.top()->getQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->EndApplication();
		this->window->close();
	}
}
void CGame::Render()
{

	this->window->clear();

	//Render Items;
	if (!this->states.empty()) {
		this->states.top()->Render(this->window);
	}

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
