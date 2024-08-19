#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
#include "GraphiscSettings.h"

class Game
{
private:

	// Variables
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	// Initialization
	void initVariables();
	void initGraphicsSettings();
	void initStateData();
	void initWindow();
	void initKeys();
	void initStates();

public:
	// Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions

	//Regular
	void endApplication();

	//Update
	void updateDT();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif // !GAME_H



