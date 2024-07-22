#include "Entity.h"

void Entity::initVariables()
{	
	this->movementComponent = NULL;
}

//Constructors/Destructors-----------------------
Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->movementComponent;
	delete this->animationComponent;
}

//Component functions----------------------------
void Entity::setTexture(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

//Functions--------------------------------------
void Entity::setPosition(const float x, const float y)
{
	
	this->sprite.setPosition(x, y);
	
}


void Entity::move(const float dir_x, const float dir_y, const float& dt)
{
	if(this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y, dt);	//Sets velocity
	}
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
