#include "State.h"

CState::CState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	:window(window), supportedKeys(supportedKeys), states(states)
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
