#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.h"
#include "Button.h"

class SettingsState : public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	// Objects
	std::map<std::string, Button*> buttons;
	std::map<std::string, DropDownList*> dropDownLists;

	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initGui();
	void supportMousePosition(bool status, sf::RenderTarget* target);

public:
	SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~SettingsState();

	//Accessors

	//Functions
	void updateInput(const float& dt);
	void updateGui(const float& dt);
	void update(const float& dt);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif