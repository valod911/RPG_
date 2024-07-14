#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class GameState : public State
{
private:
	Entity player;
public:
	GameState(sf::RenderWindow* winwow);
	virtual ~GameState();

	//Functions
	void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL); // or nullptr
};
#endif // !GAMESTATE_H
