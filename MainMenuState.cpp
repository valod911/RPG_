#include "MainMenuState.h"
//Initialization functions
void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw"ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Font/BankGothic Md BT Medium.otf"))
	{
		throw("ERROR::MAIN_MENU_STATE::COULD NOT LOAT FONT");
	}
}

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("config/mainmenustate_keybinds.ini");

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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100, 250, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS_STATE"] = new Button(100, 350, 150, 50,
		&this->font, "Settings",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));
	
	this->buttons["EXIT_STATE"] = new Button(100, 450, 150, 50,
		&this->font, "Exit",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200));

}

void MainMenuState::supportMousePosition(bool status, sf::RenderTarget* target)
{
	//Support function for rendering the cursor position on the screen;
	if (status)
	{
		sf::Text mouseText;
		mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
		mouseText.setFont(this->font);
		mouseText.setCharacterSize(12);
		std::stringstream ss;
		ss << this->mousePosView.x << "  " << this->mousePosView.y;
		mouseText.setString(ss.str());
		target->draw(mouseText);
	}
}

// Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{	
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it; it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

// Functions

void MainMenuState::updateInput(const float& dt)
{

}

void MainMenuState::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionality*/
	for (auto &it :this->buttons )
	{
		it.second->update(this->mousePosView);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}
	
	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);

	this->supportMousePosition(false, target);
	
}

