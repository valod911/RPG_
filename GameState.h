#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class GameState : public State
{
private:
public:
	GameState(sf::RenderWindow* winwow);
	virtual ~GameState();

	//Functions
	void endState();
	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};
#endif // !GAMESTATE_H
