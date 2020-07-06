#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class CGameState : public CState
{
public:
	CGameState(RenderWindow* window);
	virtual ~CGameState();

private:

public:

	void EndState();

	void UpdateKeybinds(const float& deltatime);
	void Update(const float& deltatime);
	void Render(RenderTarget* target = nullptr);

};

#endif // !GAMESTATE_H