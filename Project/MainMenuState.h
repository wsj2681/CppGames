#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class CMainMenuState : public CState
{
public:
	CMainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states);
	virtual ~CMainMenuState();

private:
	RectangleShape background;
	Font Font;
	void InitFonts();
	void InitKeybinds();
public:

	void EndState();

	void UpdateInput(const float& deltatime);
	void Update(const float& deltatime);
	void Render(RenderTarget* target = NULL);
};

#endif // !MAINMENUSTATE_H