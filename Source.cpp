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

int main()
{
	// Initialize Game Objects:
	Init();

	
	// Game loop will begin here
	while (Window.isOpen())
	{
		//Handle Keyboard Events
		
		//Upadte Game Objects in the sene
		Window.clear(sf::Color::Red);

		//renderGame Objects
		//here we call the objects
		Draw();
		Window.display();
	}
	return 0;
}