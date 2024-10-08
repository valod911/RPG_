#include "stdafx.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
}

//Accessors
const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

//Functions

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case movement_states::IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;

		break;

	case movement_states::MOVING:
		if (this->velocity.x != 0.f && this->velocity.y != 0.f)
			return true;

		break;

	case movement_states::MOVING_LEFT:
		if (this->velocity.x < 0)
			return true;

		break;

	case movement_states::MOVING_RIGHT:
		if (this->velocity.x > 0)
			return true;

		break;

	case movement_states::MOVING_UP:
		if (this->velocity.y < 0)
			return true;

		break;

	case movement_states::MOVING_DOWN:
		if (this->velocity.y > 0)
			return true;

		break;

	}

	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	/*Accelerating a sprite until it reaches the max velocity*/

	this->velocity.x += this->acceleration * dir_x;

	this->velocity.y += this->acceleration * dir_y;

}

void MovementComponent::update(const float& dt)
{
	/*Decelerate the sprite and controls the maximum velocity.
	Moves the sprite.*/
	if (this->velocity.x > 0.f)	//Check for positive x
	{
		//Max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Deceleration
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f)	//Check for negative x
	{
		//Max velocity check x
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Deceleration
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;

	}

	if (this->velocity.y > 0.f)	//Check for positive y
	{
		//Max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Deceleration
		this->velocity.y -= deceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;
	}
	else if (this->velocity.y < 0.f)	//Check for negative y
	{
		//Max velocity check y
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Deceleration
		this->velocity.y += deceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;

	}
	//Final move
	this->sprite.move(this->velocity * dt);
	
}
