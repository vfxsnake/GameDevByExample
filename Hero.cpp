#include "Hero.h"
#include <iostream>
// Constructor and Destructor implementation
Hero::Hero()
{
	//
}
Hero::~Hero()
{
	//
}

void Hero::Init(std::string TextureName, sf::Vector2f Position, float Mass)
{
	m_Position = Position;
	m_Mass = Mass;
	m_Grounded = false;

	m_Texture.loadFromFile(TextureName.c_str());
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(m_Position);
	m_Sprite.setOrigin(m_Texture.getSize().x/2, m_Texture.getSize().y/2);

	
}

void Hero::Update(float Dt)
{
	// velocity - weith
	m_Velocity -= m_Mass * m_Gravity * Dt;
	//std::cout << " Force =  " << m_Velocity << std::endl;
	m_Position.y -= m_Velocity * Dt;
	m_Sprite.setPosition(m_Position);

	if (m_Position.y >= 768 * 0.75f)
	{
		m_Position.y = 768 * 0.75f;
		m_Velocity = 0;
		m_Grounded = true;
		JumpCount = 0;
	}
}

void Hero::Jump(float Velocity)
{
	std::cout << " Jumping "<< std::endl;
	if (JumpCount < 2)
	{
		JumpCount ++;
		m_Velocity = Velocity;
		m_Grounded = false;
	}
}

sf::Sprite Hero::GetSprite()
{
	return m_Sprite;
}