#include "Player.h"
//Initialization functions-----------------------
void Player::initVariables()
{
}

void Player::initComponents()
{

}

//Constructors/Destructors-----------------------
Player::Player(float x, float y,sf::Texture& texture_sheet)
{
	this->initVariables();
	
	this->setPosition(x, y);

	this->initComponents();

	//this->createHitboxComponent(this->sprite, 0.f, 0.f, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	this->createHitboxComponent(this->sprite, 40.f, 65.f, 55, 64);
	//std::cout << this->sprite.getGlobalBounds().width;
	this->createMovementComponent(100.f, 5.f, 3.f);
	this->createAnimationComponent(texture_sheet);

	this->animationComponent->addAnimation("IDLE", 10.f, 0, 0, 6, 0, 128, 128);
	this->animationComponent->addAnimation("WALK", 10.f, 0, 1, 6, 1, 128, 128);
}

Player::~Player()
{
}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	if (this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE", dt);
	else if(this->movementComponent->getState(MOVING_LEFT))
	{
		this->sprite.setOrigin(129.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent->play("WALK", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT))
	{
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent->play("WALK", dt);
	}
	else if (this->movementComponent->getState(MOVING_UP))
	{
		this->animationComponent->play("WALK", dt);
	}
	else if (this->movementComponent->getState(MOVING_DOWN))
	{
		this->animationComponent->play("WALK", dt);
	}

	this->hitboxComponent->update();
}
