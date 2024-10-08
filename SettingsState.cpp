#include "stdafx.h"
#include "SettingsState.h"
//Initialization functions-----------------------

void SettingsState::initVariables()
{
	this->modes = sf::VideoMode::getFullscreenModes();
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
	
	std::vector<std::string> modes_str;
	for (auto& i : this->modes) {
		modes_str.push_back(std::to_string(i.width) + 'x' + std::to_string(i.height));
	}
	//std::string li[] = { "1920x1080", "800x600", "640x480" };
	this->dropDownLists["RESOLUTION"] = new DropDownList(400, 275, 200, 50, font, modes_str.data(), modes_str.size());
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

void SettingsState::initText()
{
	this->optionsText.setFont(this->font);
	this->optionsText.setPosition(sf::Vector2f(100.f, 270.f));
	this->optionsText.setCharacterSize(30);
	this->optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	this->optionsText.setString("Resolution \n\nFullscreen \n\nVsync \n\nAntialiasing \n\n");
}

//Constructors/Destructors----------------------
SettingsState::SettingsState(StateData* state_data)
	:State(state_data)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->initText();
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
		//TEST REMOVE LATER
		this->stateData->gfxSettings->resolution = this->modes[this->dropDownLists["RESOLUTION"]->getActiveElementId()];

		this->window->create(this->stateData->gfxSettings->resolution, this->stateData->gfxSettings->title, sf::Style::Default);
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

	target->draw(this->optionsText);

	this->supportMousePosition(true, target);

}

