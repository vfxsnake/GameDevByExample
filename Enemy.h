#pragma once
#include "SFML/Graphics.hpp"
class Enemy
{
public:
	Enemy();
	~Enemy();
	
	void Init(std::string textureName, sf::Vector2f position, float Speed);
	void Update(float Dt);
	sf::Sprite GetSprite();

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
	float m_Speed;
};

