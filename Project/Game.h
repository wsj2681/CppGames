#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;

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

	//Initalization
	void InitWindow();

public:

	//Funtions
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
};

#endif