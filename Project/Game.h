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

	map<string, int> supportedKeys;

	//Initalization
	void InitWindow();
	void InitKeys();
	void InitStates();

public:

	//Reguler
	void EndApplication();

	//Update
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();

	//Render
	void Render();
	
	//Core
	void Run();
};

#endif