#include "Hero.h"
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

//Chapter 4 p123 point 7 implemented. to do point 8