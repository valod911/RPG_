#ifndef STATE_H
#define STATE_H

#include "Player.h"
#include "GraphiscSettings.h"

class State;

class StateData {
public:
	StateData() {};
	
	//Variables
	float gridSize;
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	std::map < std::string, int > * supportedKeys;
	std::stack<State*>* states;
};

class State
{
	// This Abstract class
private:

protected:
	StateData* stateData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;
	bool paused;
	float keytime;
	float keyTimeMax;
	float gridSize;

	sf::Vector2i mousePosScreen;	//current position of the mouse in desktop coordinates.
	sf::Vector2i mousePosWindow;	//current position of the mouse in window coordinates.
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	//Resourses
	std::map<sf::String, sf::Texture> textures;

	//Functions
	virtual void initKeybinds() = 0;


public:
	//State(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	State(StateData* state_data);
	virtual ~State();

	//Accessors
	const bool& getQuit() const;
	const bool getKeytime();

	//Functions
	virtual void updateMousePosition();
	virtual void endState();
	void pauseState();
	void unpauseState();
	virtual void updateKeytime(const float& dt);

	// if the functions are virtual, then this class is abstract
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;	// NULL or nullptr
};

#endif