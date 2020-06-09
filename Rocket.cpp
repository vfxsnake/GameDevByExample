#include "Rocket.h"
Rocket::Rocket()
{
}

Rocket::~Rocket()
{
}

void Rocket::Init(std::string TextureName, sf::Vector2f Position, float Speed)
{
	m_Speed = Speed;
	m_Position = Position;

	// load the texture:
	m_Texture.loadFromFile(TextureName.c_str());
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(m_Position);
	m_Sprite.setOrigin(m_Texture.getSize().x / 2, m_Texture.getSize().y / 2);
}

void Rocket::Update(float Dt)
{
	m_Sprite.move(m_Speed * Dt, 0);
}

sf::Sprite Rocket::GetSprite()
{
	return m_Sprite;
}