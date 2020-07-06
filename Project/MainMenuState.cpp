#include "MainMenuState.h"

CMainMenuState::CMainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	: CState(window, supportedKeys, states)
{
	this->InitFonts();
	this->InitKeybinds();
	this->InitButtons();


	this->background.setSize(Vector2f(window->getSize()));
	this->background.setFillColor(Color::Magenta);
}

CMainMenuState::~CMainMenuState()
{
	auto it = this->buttons.begin();

	for (; it != this->buttons.end(); ++it) {
		delete it->second;
	}
}

void CMainMenuState::InitFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR : MAINMENUSTATE - FONT NOT LOAD");
	}

}

void CMainMenuState::InitKeybinds()
{
	ifstream in("Config/mainmenustate_keybinds.ini");

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

void CMainMenuState::InitButtons()
{
	this->buttons["GAME_STATE"] = new CButton(100, 100, 150, 50,
		&this->font, "New Game",
		Color::White, Color::Blue, Color::Yellow);

	this->buttons["EXIT_STATE"] = new CButton(100, 300, 150, 50,
		&this->font, "Quit",
		Color::White, Color::Blue, Color::Yellow);
}

void CMainMenuState::EndState()
{
	cout << "MinMenuState is End" << endl;
}

void CMainMenuState::UpdateInput(const float& deltatime)
{
	this->CheckForQuit();

}

void CMainMenuState::UpdateButtons()
{
	
	for (const auto& it : this->buttons) {
		it.second->Update(this->mousePosView);
	}

	//New Game
	if (this->buttons["GAME_STATE"]->isPressd()) {
		this->states->push(new CGameState(this->window, this->supportedKeys, this->states));
	}
	
	//Quit Game
	if (this->buttons["EXIT_STATE"]->isPressd()) {
		this->quit = true;
	}

}

void CMainMenuState::Update(const float& deltatime)
{
	this->UpdateMousePositions();
	this->UpdateInput(deltatime);

	this->UpdateButtons();
}

void CMainMenuState::RenderButtons(RenderTarget* target)
{
	for (const auto& it : this->buttons) {
		it.second->Render(target);
	}
}


void CMainMenuState::Render(RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->RenderButtons(target);
}
