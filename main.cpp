#include "SFML/Graphics.hpp"
sf::Vector2f ViewSize(1024,768);
sf::VideoMode Vm(ViewSize.x, ViewSize.y);
sf::RenderWindow Window(Vm, "Hello SFML  Game!!!", sf::Style::Default);

sf::Vector2f PlayerPosition;
bool PlayerMoving = false;

sf::Texture SkyTexture;
sf::Sprite SkySprite;

sf::Texture BgTexture;
sf::Sprite BgSprite;

void Init()
{
	SkyTexture.loadFromFile("Assets/graphics/sky.png"); // loads the texture
	SkySprite.setTexture(SkyTexture);

	BgTexture.loadFromFile("Assets/graphics/bg.png");
	BgSprite.setTexture(BgTexture);
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
}


void Draw()
{
	Window.draw(SkySprite);
	Window.draw(BgSprite);
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