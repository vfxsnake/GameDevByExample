#include "SFML/Graphics.hpp"

// windwo size variable
sf::Vector2f ViewSize(1024, 768);
sf::VideoMode ViewMode(ViewSize.x, ViewSize.y);
sf::RenderWindow Window(ViewMode, "Hello SFML Game!!", sf::Style::Default);

// Global declaration of sprite and Texture classes
// sky layer
sf::Texture SkyTexture;
sf::Sprite SkySprite;
// background layer
sf::Texture BgTexture;
sf::Sprite BgSprite;

//Hero Layer
sf::Texture HeroTexture;
sf::Sprite HeroSprite;
sf::Vector2f PlayerPosition;
//bool player moving
bool PlayerMoving = false;


// Function to initialze textures and Sprites
void Init()
{
	SkyTexture.loadFromFile("Assets/graphics/sky.png"); // loads the texture
	SkySprite.setTexture(SkyTexture);

	BgTexture.loadFromFile("Assets/graphics/bg.png");
	BgSprite.setTexture(BgTexture);

	HeroTexture.loadFromFile("Assets/graphics/hero.png");
	HeroSprite.setTexture(HeroTexture);
	HeroSprite.setPosition(sf::Vector2f(ViewSize.x/2, ViewSize.y/2));
	// the size parameter comes from the texture size
	HeroSprite.setOrigin(HeroTexture.getSize().x/2, HeroTexture.getSize().y/2);

}

void Draw()
{
	Window.draw(SkySprite);
	Window.draw(BgSprite);
	Window.draw(HeroSprite);
}

void UpdateInput()
{
	sf::Event Event;
	while (Window.pollEvent(Event))
	{
		// key press event:
		if (Event.type == sf::Event::KeyPressed)
		{
			if (Event.key.code == sf::Keyboard::Right)
			{
				PlayerMoving = true;
			}
		}
		// key released event
		if (Event.type == sf::Event::KeyReleased)
		{
			if (Event.key.code == sf::Keyboard::Right)
			{
				PlayerMoving = false;
			}
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
	if (PlayerMoving)
	{
		HeroSprite.move(50.0f * Dt, 0);
	}
}

int main()
{
	//initilize clock
	sf::Clock Clock;

	// Initialize Game Objects:
	Init();

	// Game loop will begin here
	while (Window.isOpen())
	{
		//Handle Keyboard Events
		UpdateInput();

		// update game before drawing
		sf::Time Dt = Clock.restart();
		Update(Dt.asSeconds());

		//Upadte Game Objects in the sene
		Window.clear(sf::Color::Red);

		//renderGame Objects
		//here we call the objects
		Draw();
		Window.display();
	}
	return 0;
}