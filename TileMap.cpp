#include "stdafx.h"
#include "TileMap.h"
//Constructors/Destructors----------------------
TileMap::TileMap()
{
	this->gridSizeU = 50;
	this->maxSize = sf::Vector2u(5000, 5000);
	this->layers = 5;
	
	for (size_t x = 0; x < this->maxSize.x; x++)
	{
		this->map.push_back(std::vector<std::vector <Tile>>());
		for (size_t y = 0; y < this->maxSize.y; y++)
		{
			this->map[x].push_back(std::vector<Tile>());
			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].push_back(Tile());
			}
		}
	}
}

TileMap::~TileMap()
{
}

//Initialization functions-----------------------
//Accessors--------------------------------------
//Functions--------------------------------------