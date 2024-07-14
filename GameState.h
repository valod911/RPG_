#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class GameState : public State
{
private:
	Entity player;

	//Functions
	void initKeybinds();

public:
	GameState(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	//Functions
	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL); // or nullptr
};
#endif // !GAMESTATE_H
