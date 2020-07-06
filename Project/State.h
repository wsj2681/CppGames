#ifndef STATE_H
#define STATE_H


#include "Entity.h"


class CState
{
public:
	CState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states);
	virtual ~CState();

private:

protected:
	stack<CState*>* states;
	RenderWindow* window{ nullptr };
	map<string, int>* supportedKeys;
	map<string, int> keybinds;
	bool quit{ false };

	vector<Texture> vTextures;

	virtual void InitKeybinds() = 0;
public:

	const bool& getQuit()const;

	virtual void CheckForQuit();

	virtual void EndState() = 0;
	virtual void UpdateInput(const float& deltatime) = 0;
	virtual void Update(const float& deltatime) = 0;
	virtual void Render(RenderTarget* target = NULL) = 0;

};

#endif // ! STATE_H