#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class PauseMenu
{
private:
	//fullscrean background 
	// buttons
	// map with buttons
	sf::RectangleShape background;
	sf::RectangleShape container;

	std::map<std::string, Button*> buttons;


public:
	PauseMenu(sf::RenderWindow& window);
	virtual ~PauseMenu();

	//Funcions
	void update();
	void render(sf::RenderTarget& target);
};

#endif
