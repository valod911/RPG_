#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Font/BankGothic Md BT Medium.otf"))
	{
		throw("ERROR::MAIN_MENU_STATE::COULD NOT LOAT FONT");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();
}

// Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{	
	this->initFonts();
	this->initKeybinds();

	this->gamestate_btn = new Button(100,100,150,50,
		&this->font,"New Game",
		sf::Color(70,70,70,200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}

// Functions
void MainMenuState::endState()
{
	std::cout << "Ending GameState\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);

	this->gamestate_btn->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->gamestate_btn->render(target);
}

