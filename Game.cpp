#include "Game.h"
// Static functions

// Initialization functions

void Game::initWinwow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "c++ SFML RPG");
}

// Constructors/Destructors
Game::Game()
{   
    /*Create a SFML window using options from a window.ini file.*/
    this->initWinwow();
}

Game::~Game()
{
	delete this->window;
}

// Functions

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (sfEvent.type == sf::Event::Closed)
            this->window->close();
    }

    
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    // Render items

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

