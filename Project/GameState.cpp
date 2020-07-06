#include "GameState.h"

CGameState::CGameState(RenderWindow* window): CState(window)
{
}

CGameState::~CGameState()
{
}

void CGameState::EndState()
{
	cout << "GameState is End" << endl;
}

void CGameState::UpdateKeybinds(const float& deltatime)
{
	this->CheckForQuit();
}

void CGameState::Update(const float& deltatime)
{
	this->UpdateKeybinds(deltatime);

	if (Keyboard::isKeyPressed(Keyboard::A))
		cout << "A" << endl;
}

void CGameState::Render(RenderTarget* target)
{

}
