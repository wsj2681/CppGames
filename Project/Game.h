#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class CGame
{
public:
	CGame();
	virtual ~CGame();

private:

	//Variables
	RenderWindow* window{ nullptr };
	Event sfevent;

	Clock deltaClock;
	float deltatime{ 0.f };

	stack<CState*> states;

	//Initalization
	void InitWindow();
	void InitStates();
public:

	//Funtions
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};

#endif