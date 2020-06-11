// Include headers:
#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "Enemy.h"
#include "Rocket.h"

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
void Shoot();
void Reset();

//check collision:
bool CheckCollision(sf::Sprite Sprite1, sf::Sprite Sprite2);

// Hero class instace
Hero HeroGirl;

// Enemy class  multiple instances instaces
std::vector<Enemy*> Enemies;

// rocket multiple instances
std::vector<Rocket*> Rockets;

float CurrentTime;
float PrevTime = 0.0f;

// score variable
int Score = 0;
// game over variable
bool GameOver = true;

// create text
sf::Font HeadingFont;
sf::Text HeadingText;


void Init()
{
	SkyTexture.loadFromFile("Assets/graphics/sky.png"); // loads the texture
	SkySprite.setTexture(SkyTexture);

	BgTexture.loadFromFile("Assets/graphics/bg.png");
	BgSprite.setTexture(BgTexture);

	//load Font
	HeadingFont.loadFromFile("Assets/fonts/SnackerComic.ttf");
	HeadingText.setFont(HeadingFont);
	HeadingText.setString("Tiny Bazooka");
	HeadingText.setCharacterSize(84);
	HeadingText.setFillColor(sf::Color::Red);

	sf::FloatRect HeadingBounds = HeadingText.getLocalBounds();
	HeadingText.setOrigin(HeadingBounds.width / 2, HeadingBounds.height / 2);
	HeadingText.setPosition(sf::Vector2f(ViewSize.x / 2, ViewSize.y / 2));
	
	// Chapter 5 p150 index 7 to do add score to window .*************************

	// init HeroGirl texture, position , mass
	HeroGirl.Init("Assets/graphics/hero.png", sf::Vector2f(ViewSize.x *0.25f,ViewSize.y * 0.1f),
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


			if (Event.key.code == sf::Keyboard::Up)
			{
				HeroGirl.Jump(750.0f);
			}

			if (Event.key.code == sf::Keyboard::Space)
			{
				if (GameOver)
				{
					GameOver = false;
					Reset();
				}
				Shoot();
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
	CurrentTime += Dt;
	//Spawn Enemies
	if (CurrentTime >= PrevTime + 1.125f)
	{
		SpawnEnemy();
		PrevTime = CurrentTime;
	}

	// updating Enemies
	for (int i = 0; i < Enemies.size(); i++)
	{
		Enemy* CurrentEnemy = Enemies[i];
		CurrentEnemy->Update(Dt);
		if (CurrentEnemy->GetSprite().getPosition().x < 0)
		{
			Enemies.erase(Enemies.begin() + i);
			delete(CurrentEnemy);
			GameOver = true;
		}
	}

	// updating Rockets:
	for (int i = 0; i < Rockets.size(); i++)
	{
		Rocket* rocket = Rockets[i];
		rocket->Update(Dt);

		if (rocket->GetSprite().getPosition().x > ViewSize.x)
		{
			Rockets.erase(Rockets.begin()+i);
			printf("Deliting Roket");
			delete(rocket);
		}
	}

	// check rocket collisiont with enemys:
	for (int i = 0; i < Rockets.size(); i++)
	{
		for (int j = 0; j < Enemies.size(); j++)
		{
			Rocket* rocket = Rockets[i];
			Enemy* enemy = Enemies[j];

			if (CheckCollision(rocket->GetSprite(), enemy->GetSprite()))
			{
				Score++;
				printf("score is : %i \n", Score);
			
				Rockets.erase(Rockets.begin() + i);
				Enemies.erase(Enemies.begin() + j);
				delete(rocket);
				delete(enemy);
				printf("roket, enemy intersection");
			}
		}
	}
}

void Reset()
{
	Score = 0;
	CurrentTime = 0.0f;
	PrevTime = 0.0f;
	for (Enemy* enemy : Enemies)
	{
		delete(enemy); // clear memory from enemies
	}

	for (Rocket* rocket : Rockets)
	{
		delete(rocket); // clear memory from rockets
	}

	Enemies.clear(); // cleaan Enemies vector
	Rockets.clear(); // clean Rockets vector
	printf("reset Done \n");
}

void Draw()
{
	Window.draw(SkySprite);
	Window.draw(BgSprite);
	Window.draw(HeroGirl.GetSprite());

	if (GameOver)
	{
		Window.draw(HeadingText);
	}

	// drawing enemies:
	for (Enemy* enemy : Enemies) // for loop vector iter form
	{
		Window.draw(enemy->GetSprite());
	}

	// Drawing Rockets:
	for (Rocket* rocket : Rockets)
	{
		Window.draw(rocket->GetSprite());
	}

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

void Shoot()
{
	Rocket* rocket = new Rocket();
	rocket->Init("Assets/graphics/rocket.png", HeroGirl.GetSprite().getPosition(), 400.0f);
	Rockets.push_back(rocket);
}

bool CheckCollision(sf::Sprite Sprite1, sf::Sprite Sprite2)
{
	sf::FloatRect Shape1 = Sprite1.getGlobalBounds();
	sf::FloatRect Shape2 = Sprite2.getGlobalBounds();
	if (Shape1.intersects(Shape2))
	{
		return true;
	}

	else
	{
		return false;
	}
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
		if (!GameOver)
		{
			Update(Dt.asSeconds());
		}
		
		Window.clear(sf::Color::Red);
		Draw();

		Window.display();
	}
	return 0;
}