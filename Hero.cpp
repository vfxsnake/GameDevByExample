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

void Hero::Init(std::string TextureName, int FrameCount, float AnimDuration,
				sf::Vector2f Position, float mass)
{
	m_Position = Position;
	m_Mass = mass;
	m_Grounded = false;

	m_Texture.loadFromFile(TextureName.c_str());
	m_SpriteSize = sf::Vector2i(92,126);
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(sf::IntRect(0, 0, m_SpriteSize.x, m_SpriteSize.y));
	m_Sprite.setPosition(m_Position);
	m_Sprite.setOrigin(m_SpriteSize.x /2, m_SpriteSize.y / 2);

	m_FrameCount = FrameCount;
	m_AnimDuration = AnimDuration;
}

void Hero::Update(float Dt)
{
	// Animate Sprite:
	m_ElapsedTime += Dt;
	int AnimFrame = static_cast<int> ((m_ElapsedTime / m_AnimDuration) * m_FrameCount) % m_FrameCount;
	m_Sprite.setTextureRect(sf::IntRect(AnimFrame * m_SpriteSize.x, 0, m_SpriteSize.x, m_SpriteSize.y));
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