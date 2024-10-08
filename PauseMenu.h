#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Button.h"

class PauseMenu
{
private:
	sf::Font& font;
	sf::Text menuText;

	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;

	//Private functions



public:
	PauseMenu(sf::RenderWindow& window, sf::Font& font);
	virtual ~PauseMenu();

	//Accessors
	std::map<std::string, Button*>& getButtons();

	//Funcions
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);
	void addButton(const std::string key, float y, const std::string text);
	const bool isButtonPressed(const std::string key);
};

#endif
