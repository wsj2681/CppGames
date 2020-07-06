#include "GameState.h"

CGameState::CGameState(RenderWindow* window, map<string, int>* supportedKeys)
	: CState(window, supportedKeys)
{
	this->InitKeybinds();
}

CGameState::~CGameState()
{
}

void CGameState::InitKeybinds()
{
	this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
	this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
	this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
	this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

void CGameState::EndState()
{
	cout << "GameState is End" << endl;
}

void CGameState::UpdateInput(const float& deltatime)
{
	this->CheckForQuit();

	//Update Player input
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.Move(deltatime, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.Move(deltatime, 1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.Move(deltatime, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.Move(deltatime, 0.f, 1.f);
}

void CGameState::Update(const float& deltatime)
{
	this->UpdateInput(deltatime);

	this->player.Update(deltatime);
}

void CGameState::Render(RenderTarget* target)
{
	if (target) 
	{
		this->player.Render(target);
	}
	else
	{
		this->player.Render(this->window);
	}
}
