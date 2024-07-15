#include "State.h"

State::State(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys)
{
	this->window = winwow;
	this->supportedKeys = supportedKeys;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		this->quit = true;
	}
}
