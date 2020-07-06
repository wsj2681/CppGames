#include "GameState.h"

CGameState::CGameState(RenderWindow* window): CState(window)
{
}

CGameState::~CGameState()
{
}

void CGameState::EndState()
{
}

void CGameState::Update(const float& deltatime)
{
	cout << "Hello" << endl;
}

void CGameState::Render(RenderTarget* target)
{

}
