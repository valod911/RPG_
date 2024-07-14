#ifndef STATE_H
#define STATE_H

#include "Entity.h"


class State
{
	// This Abstract class
private:

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* winwow);
	virtual ~State();

	const bool& getQuit() const;
	virtual void checkForQuit();
	// if the functions are virtual, then this class is abstract
	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif