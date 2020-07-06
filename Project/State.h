#ifndef STATE_H
#define STATE_H

#include "Game.h"
#include <vector>

class CState
{
public:
	CState();
	virtual ~CState();

private:
	vector<Texture> vTextures;
	
public:

	virtual void Update() = 0;
	virtual void Render() = 0;
};

#endif // ! STATE_H