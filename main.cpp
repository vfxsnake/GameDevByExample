// Include headers:
#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

// Static Variables
sf::Vector2f ViewSize(1024,768);
sf::VideoMode Vm(ViewSize.x, ViewSize.y);
sf::RenderWindow Window(Vm, "Hello SFML  Game!!!", sf::Style::Default);

// Level creation
sf::Texture SkyTexture;
sf::Sprite SkySprite;

sf::Texture BgTexture;
sf::Sprite BgSprite;

// fucntion prototypes
void SpawnEnemy();

// Hero class instace
Hero HeroGirl;

// Enemy class  multiple instances instaces
std::vector<Enemy*> Enemies;


void Init()
{
	SkyTexture.loadFromFile("Assets/graphics/sky.png"); // loads the texture
	SkySprite.setTexture(SkyTexture);

	BgTexture.loadFromFile("Assets/graphics/bg.png");
	BgSprite.setTexture(BgTexture);

	// init HeroGirl texture, position , mass
	HeroGirl.Init("Assets/graphics/hero.png", sf::Vector2f(ViewSize.x *0.25f,ViewSize.y * 0.5f),
					200);

	// set ramdom seed
	srand((int)time(0));

}

void UpdateInput()
{
	sf::Event Event;
	while (Window.pollEvent(Event))
	{
		// key press event:
		if (Event.type == sf::Event::KeyPressed)
		{
			/*
			if (Event.key.code == sf::Keyboard::Right)
			{
				PlayerMoving = true;
			}*/

			if (Event.key.code == sf::Keyboard::Up)
			{
				HeroGirl.Jump(750.0f);
			}
		}
		// key released event
		if (Event.type == sf::Event::KeyReleased)
		{
			/*
			if (Event.key.code == sf::Keyboard::Right)
			{
				PlayerMoving = false;
			}*/
		}

		// handle the exit of the game closing the window.
		if (Event.key.code == sf::Keyboard::Escape || Event.type == sf::Event::Closed)
		{
			Window.close();
		}
	}
}

void Update(float Dt)
{
	HeroGirl.Update(Dt);
}


void Draw()
{
	Window.draw(SkySprite);
	Window.draw(BgSprite);
	Window.draw(HeroGirl.GetSprite());
}

void SpawnEnemy()
{
	int randLoc = rand() % 3;
	sf::Vector2f EnemyPos;
	float Speed;

	switch (randLoc)
	{
	case 0:
		EnemyPos = sf::Vector2f(ViewSize.x, ViewSize.y * 0.75f);
		Speed = -400; 
		break;
	
	case 1:
		EnemyPos = sf::Vector2f(ViewSize.x, ViewSize.y * 0.60f);
		Speed = -550; 
		break;
	case 2:
		EnemyPos = sf::Vector2f(ViewSize.x, ViewSize.y * 0.40f);
		Speed = -650; 
		break;

	default:
		printf("incorrect values \n");
		return;
	}

	Enemy* EnemySpawn = new Enemy();
	EnemySpawn->Init("Assets/graphics/enemy.png", EnemyPos, Speed);
	Enemies.push_back(EnemySpawn);
	// Chapter 4 p.133 section 6 
}

int main()
{
	sf::Clock Clock;
	Window.setFramerateLimit(60);
	Init();

	while (Window.isOpen())
	{
		UpdateInput();

		sf::Time Dt = Clock.restart();
		Update(Dt.asSeconds());
		
		Window.clear(sf::Color::Red);

		Draw();

		Window.display();
	}
	return 0;
}