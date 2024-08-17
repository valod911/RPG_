#include "SettingsState.h"
//Initialization functions-----------------------

void SettingsState::initVariables()
{
}

void SettingsState::initBackground()
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

void SettingsState::initFonts()
{
	if (!this->font.loadFromFile("Font/BankGothic Md BT Medium.otf"))
	{
		throw("ERROR::MAIN_MENU_STATE::COULD NOT LOAT FONT");
	}
}

void SettingsState::initKeybinds()
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

void SettingsState::initGui()
{
	this->buttons["BACK"] = new Button(
		450.f, 700.f, 250.f, 50.f,
		&this->font, "Back", 22,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["APPLY"] = new Button(
		150.f, 700.f, 250.f, 50.f,
		&this->font, "Apply", 22,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	std::string li[] = { "1920x1080", "800x600", "640x480" };
	this->dropDownLists["RESOLUTION"] = new DropDownList(400, 275, 200, 50, font, li, 3);
}

void SettingsState::supportMousePosition(bool status, sf::RenderTarget* target)
{
	//Support function for rendering the cursor position on the screen;
	if (status)
	{
		sf::Text mouseText;
		float x, y;
		x = this->mousePosView.x;
		y = this->mousePosView.y;
		if (y < 50)
			y = y + 25;
		else
			y = y - 50;
		mouseText.setPosition(x, y);
		mouseText.setFont(this->font);
		mouseText.setCharacterSize(12);
		std::stringstream ss;
		ss << this->mousePosView.x << "  " << this->mousePosView.y;
		mouseText.setString(ss.str());
		target->draw(mouseText);
	}
}

//Constructors/Destructors----------------------
SettingsState::SettingsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
}

SettingsState::~SettingsState()
{
	auto it = this->buttons.begin();
	for (it; it != this->buttons.end(); ++it)
	{
		delete it->second;
	}

	auto it2 = this->dropDownLists.begin();
	for (it2; it2 != this->dropDownLists.end(); ++it2)
	{
		delete it2->second;
	}

}

//Accessors--------------------------------------

//Functions--------------------------------------
void SettingsState::updateInput(const float& dt)
{

}

void SettingsState::updateGui(const float& dt)
{
	/*Updates all the buttons in the state and handles their functionality*/
	//Buttons
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//Button functionality
	//Quit the game
	if (this->buttons["BACK"]->isPressed())
	{
		this->endState();
	}

	//Apply selected settigns
	if (this->buttons["APPLY"]->isPressed())
	{
		
	}

	//Dropdown lists
	for (auto& it : this->dropDownLists)
	{
		it.second->update(this->mousePosView, dt);
	}

	//Dropdown lists funcionality

}

void SettingsState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateGui(dt);
}

void SettingsState::renderGui(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}

	for (auto& it : this->dropDownLists)
	{
		it.second->render(target);
	}
}

void SettingsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderGui(*target);

	this->supportMousePosition(true, target);

}

