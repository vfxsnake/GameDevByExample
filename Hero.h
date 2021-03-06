#pragma once
#include "SFML/Graphics.hpp"

class Hero
{
public:
	//constructor
	Hero();

	// destructure
	~Hero();

	void Init(std::string TextureName, int FrameCount, float AnimDuration, 
			  sf::Vector2f Position, float mass);
	
	void Update(float Dt);
	
	void Jump(float Velocity);
	
	sf::Sprite GetSprite();

private:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;

	int JumpCount = 0;
	float m_Mass = 200;
	float m_Velocity = 0;
	const float m_Gravity = 9.8f;
	bool m_Grounded = false;

	int m_FrameCount;
	float m_AnimDuration;
	float m_ElapsedTime;
	sf::Vector2i m_SpriteSize;
};


