#include "stdafx.h"
#include "Tile.h"

Tile::Tile()
{
}

//Constructors/Destructors-----------------------
Tile::Tile(float x, float y, float gridSizeF)
{
	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setPosition(x, y);
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

