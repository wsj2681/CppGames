#include "MainMenuState.h"

CMainMenuState::CMainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	: CState(window, supportedKeys, states)
{
	this->InitKeybinds();
	this->background.setSize(Vector2f(window->getSize()));
	this->background.setFillColor(Color::Magenta);
}

CMainMenuState::~CMainMenuState()
{
}

void CMainMenuState::InitFonts()
{
	if (this->Font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR : MAINMENUSTATE - FONT NOT LOAD");
	}

}

void CMainMenuState::InitKeybinds()
{
	ifstream in("Config/gamestate_keybinds.ini");

	if (in.is_open()) {
		string key{};
		string key2{};
		while (in >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	in.close();
}

void CMainMenuState::EndState()
{
	cout << "GameState is End" << endl;
}

void CMainMenuState::UpdateInput(const float& deltatime)
{
	this->CheckForQuit();

}

void CMainMenuState::Update(const float& deltatime)
{
	this->UpdateMousePositions();
	this->UpdateInput(deltatime);

}

void CMainMenuState::Render(RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
}
