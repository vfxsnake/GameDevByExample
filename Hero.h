#pragma once
#include "SFML/Graphics.hpp"

class Hero
{
public:
	//constructor
	Hero();

	// destructure
	~Hero();

	void Init(std::string TextureName, sf::Vector2f Position, float mass);
	void Update(float Dt);
	void Jump(float Velocity);
	sf::Sprite GetSprite();

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;

	int Jumpcount = 0;
	float m_Mass;
	float m_Velocity;
	const float m_Gravity = 9.8f;
	bool m_Grounded;
};

