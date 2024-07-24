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

	this->animationComponent->addAnimation("IDLE_RIGHT", 10.f, 0, 0, 6, 0, 128, 128);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 1, 6, 1, 128, 128);
}

Player::~Player()
{
}

//Functions
void Player::update(const float& dt)
{
	this->movementComponent->update(dt);
	if (this->movementComponent->getState(IDLE))
		this->animationComponent->play("IDLE_RIGHT", dt);
	else if(this->movementComponent->getState(MOVING_LEFT))
		this->animationComponent->play("WALK_RIGHT", dt);

	this->hitboxComponent->update();
}
