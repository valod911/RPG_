#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
}

//Constructors/Destructors-----------------------
Tile::Tile(float x, float y, float gridSizeF, sf::Texture& texture)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->shape.setFillColor(sf::Color::White);
	//this->shape.setOutlineThickness(1.f);
	//this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(x, y);
	this->shape.setTexture(&texture);
}



//Functions--------------------------------------
Tile::~Tile()
{
}

void Tile::update()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

