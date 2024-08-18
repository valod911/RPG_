#include "stdafx.h"
#include "Game.h"
// Static functions

// Initialization functions

void Game::initVariables()
{
    this->window = NULL;
    this->dt = 0.0f;
}

void Game::initGraphicsSettings()
{
    this->gfxSettings.loadFromFile("config/graphics.ini");
}

void Game::initWindow()
{
    /*Create a SFML window.*/
    if (this->gfxSettings.fullscreen)
        this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Fullscreen, this->gfxSettings.contextSettings);
    else
        this->window = new sf::RenderWindow(this->gfxSettings.resolution, this->gfxSettings.title, sf::Style::Titlebar | sf::Style::Close, this->gfxSettings.contextSettings);

    this->window->setFramerateLimit(this->gfxSettings.frameRateLimit);
    this->window->setVerticalSyncEnabled(this->gfxSettings.verticalSync);
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, this->gfxSettings, &this->supportedKeys, &this->states));
    //this->states.push(new GameState(this->window, &this->supportedKeys));
}

void Game::initKeys()
{
    std::ifstream ifs("config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();

    //DEBUG REMOVE LATER!
    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}

// Constructors/Destructors
Game::Game()
{   
    this->initVariables();
    this->initGraphicsSettings();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

// Functions

void Game::endApplication()
{
    std::cout << "Ending Application!\n";
}

void Game::updateDT()
{
    /*Updates the dt variable with the time it takes to update and render one frame.*/
    this->dt = this->dtClock.restart().asSeconds();

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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    // Render items
    if (!this->states.empty())
        this->states.top()->render();

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

