#ifndef STATE_H
#define STATE_H


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;


class CState
{
public:
	CState(RenderWindow* window);
	virtual ~CState();

private:
	RenderWindow* window{ nullptr };
	vector<Texture> vTextures;
	
public:
	virtual void EndState() = 0;

	virtual void Update(const float& deltatime) = 0;
	virtual void Render(RenderTarget* target = nullptr) = 0;

};

#endif // ! STATE_H