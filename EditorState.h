#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "State.h"
#include "Button.h"
#include "PauseMenu.h"
#include "TileMap.h"

class EditorState :
    public State
{
private:
	// Variables
	sf::Font font;
	sf::Text cursorText;
	PauseMenu* pmenu;

	// Objects
	std::map<std::string, Button*> buttons;

	TileMap* tileMap;

	//Sidebar on the left side
	sf::RectangleShape sidebar;

	sf::IntRect textureRect;
	sf::RectangleShape selectorRect;

	TextureSelector* textureSelector;

	//Functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initText();
	void initKeybinds();
	void initPauseMenu();
	void initButtons();
	void initGui();
	void initTileMap();

	void supportMousePosition(bool status, sf::RenderTarget* target);

public:
	EditorState(StateData* state_data);
	virtual ~EditorState();

	//Functions
	void updateInput(const float& dt);
	void updateEditorInput(const float& dt);
	void updateButtons();
	void updateGui(const float& dt);
	void updatePauseMenuButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void renderGui(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif // !EDITORSTATE_H
