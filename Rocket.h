#pragma once
#include "SFML/Graphics.hpp"
class Rocket
{
public:
	Rocket();
	~Rocket();

	void Init(std::string TextureName, sf::Vector2f Position, float Speed);

	void Update(float Dt);
	sf::Sprite GetSprite();

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
	float m_Speed;
};

