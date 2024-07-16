#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	// Variables
	sf::RectangleShape background;
	sf::Font font;

	// Objects
	Button* gamestate_btn;

	//Functions
	void initFonts();
	void initKeybinds();

public:
	MainMenuState(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	//Functions
	void endState();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
};
#endif //MAINMENUSTATE_H

