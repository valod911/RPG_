#ifndef BUTTON_H
#define BUTTON_H

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };


class Button
{
private:
	short unsigned button_states;
	short unsigned id;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	sf::Color outlineIdleColor;
	sf::Color outlineHoverColor;
	sf::Color outlineActiveColor;

public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
		sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent,
		short unsigned id = 0);
	~Button();

	//Accessors
	const bool isPressed() const;
	const std::string getText() const;
	const short unsigned& getId() const;

	//Modifiers
	void setText(const std::string text);
	void setId(const short unsigned id);

	//Functions
	void update(const sf::Vector2f& mousePos);
	void render(sf::RenderTarget& target);

};

class DropDownList
{
private:
	float keytime;
	float keytimeMax;
	sf::Font& font;
	Button* activeELement;
	std::vector<Button*> list;
	bool showList;

public:
	DropDownList(float x, float y, float width, float height,
		sf::Font& font, std::string list[],
		unsigned nrOfElements, unsigned default_index = 0);
	~DropDownList();

	//Accessors
	const unsigned short& getActiveElementId() const;

	//Functions
	const bool getKeytime();
	void updateKeytime(const float& dt);
	void update(const sf::Vector2f& mousePos, const float& dt);
	void render(sf::RenderTarget& target);
};

class TextureSelector
{
private:
	float gridSize; // size one tile from setting
	bool active;	
	bool hidden;	// will it be shown on screen
	Button* hide_btn;
	sf::RectangleShape bounds;	// Rect to bounds
	sf::Sprite sheet;
	sf::RectangleShape selector;// Rect to selector
	sf::Vector2u mousePosGrid;
	sf::IntRect textureRect;

	float keytime = 0;
	const float keytimeMax;	

public:
	TextureSelector(float x, float y, float width, float height, float grid_size, const sf::Texture* texture_sheet,
		sf::Font& font, std::string text);
	~TextureSelector();

	//Accessors
	const bool& getActive() const;
	const sf::IntRect& getTextureRect() const;
	const bool getKeytime();

	//Functions
	void updateKeytime(const float& dt);
	void update(const sf::Vector2i& mousePosWindow, const float& dt);
	void render(sf::RenderTarget& target);
};
#endif // !BUTTON_H
