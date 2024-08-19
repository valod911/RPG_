#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "EditorState.h"
#include "Button.h"
#include "SettingsState.h"
#include "GraphiscSettings.h"

class MainMenuState : public State
{
private:
	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	// Objects
	std::map<std::string, Button*> buttons;

	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds();
	void initButtons();

	void supportMousePosition(bool status, sf::RenderTarget* target);

public:
	MainMenuState(StateData* state_data);
	virtual ~MainMenuState();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};
#endif //MAINMENUSTATE_H

