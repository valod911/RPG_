#ifndef STATE_H
#define STATE_H

#include "Player.h"

class State
{
	// This Abstract class
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;	//current position of the mouse in desktop coordinates.
	sf::Vector2i mousePosWindow;	//current position of the mouse in window coordinates.
	sf::Vector2f mousePosView;

	//Resourses
	std::map<sf::String, sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;


public:
	State(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;
	// if the functions are virtual, then this class is abstract
	virtual void updateMousePosition();
	virtual void endState();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif