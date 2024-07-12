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

void Game::updateDT()
{
    /*Updates the dt variable with the time it takes to update and render one frame.*/
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << "\n";
}

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
    int sum = 0;
    for (size_t i = 0; i < 10000000000; i++)
    {
        sum += i;
    }
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
        this->updateDT();
        this->update();
        this->render();
    }
}

