#ifndef MOVEMENT_COMPONET_H
#define MOVEMENT_COMPONET_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class MovementComponent
{
private:
	float maxVelocity;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;

	//Init. functions

public:
	MovementComponent(float maxVelocity);
	virtual ~MovementComponent();

	//Accessors
	const sf::Vector2f& getVelocity() const;

	//Functions
	void move(const float dir_x, const float dir_y);
	void update(const float& dt);
};

#endif // !MOVEMENT_COMPONET_H