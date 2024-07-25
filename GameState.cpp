#include "GameState.h"
//Initialization functions-----------------------
void GameState::initKeybinds()
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

void GameState::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/Skeleton_Warrior_Spritelist.png"))
	{
		throw("ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_IDLE_TEXTURE");
	}
	
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, this->textures["PLAYER_SHEET"]);
}

//Constructors/Destructors----------------------
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states), pmenu(*window)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//Functions--------------------------------------

void GameState::updateInput(const float& dt)
{
	//Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(0.f, 1.f, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
	{
		if (!this->paused)
			this->pauseState();
		//else
			//this->unpauseState();
	}
		
}

void GameState::update(const float& dt)
{
	if (!this->paused)	//Unpause update
	{
		this->updateMousePosition();
		this->updateInput(dt);
		this->player->update(dt);
	}
	else //Pause update
	{
		this->pmenu.update();
	}
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player->render(*target);

	if (this->paused)	//Pause menu render
	{
		this->pmenu.render(*target);
	}
}
