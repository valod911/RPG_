#include "stdafx.h"
#include "State.h"

State::State(sf::RenderWindow* winwow, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
	this->window = winwow;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
	this->paused = false;
	this->keytime = 0.f;
	this->keyTimeMax = 10.f;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

const bool State::getKeytime()
{
	if (this->keytime >= this->keyTimeMax)
	{
		this->keytime = 0.f;
		return true;
	}
	return false;
}

//void State::checkForQuit()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
//	{
//		this->quit = true;
//	}
//}

void State::endState()
{
	this->quit = true;
}

void State::pauseState()
{
	this->paused = true;
}

void State::unpauseState()
{
	this->paused = false;
}

void State::updateKeytime(const float& dt)
{
	if (this->keytime < this->keyTimeMax)
		this->keytime += 50.f * dt;
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
