#include "State.h"

CState::CState(RenderWindow* window):window(window)
{

}

CState::~CState()
{
}

const bool& CState::getQuit() const
{
	return this->quit;
}

void CState::CheckForQuit()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		this->quit = true;
	}
}
