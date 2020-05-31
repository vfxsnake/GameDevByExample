#include "SFML/Graphics.hpp"

// windwo size variable
sf::Vector2f ViewSize(1024, 768);
sf::VideoMode ViewMode(ViewSize.x, ViewSize.y);
sf::RenderWindow Window(ViewMode, "Hello SFML Game!!", sf::Style::Default);

// Global declaration of sprite and Texture classes
sf::Texture SkyTexture;
sf::Sprite SkySprite;

// Function to initialze textures and Sprites
void init()
{
	SkyTexture.loadFromFile("Assets/graphics/sky.png"); // loads the texture
	SkySprite.setTexture(SkyTexture);
}

void draw()
{
	Window.draw(SkySprite);
}

int main()
{
	// Initialize Game Objects:
	// test rectangle:
	sf::RectangleShape Rectangle(sf::Vector2f(500.0f, 300.0f));
	
	// chapter 3 p.104 Circle, triangle creation:
	sf::CircleShape Circle(100); //creates a circle with 100 pixel radius
	Circle.setFillColor(sf::Color::Green);
	float CircleRadius = Circle.getRadius();
	Circle.setOrigin(sf::Vector2f(CircleRadius, CircleRadius));
	Circle.setPosition(ViewSize.x / 2, ViewSize.y / 2);

	sf::ConvexShape Triangle; // creates convex figures in this case a triagle
	Triangle.setPointCount(3);
	Triangle.setPoint(0, sf::Vector2f(-100, 0));
	Triangle.setPoint(1, sf::Vector2f(0, -100));
	Triangle.setPoint(2, sf::Vector2f(100,0));
	Triangle.setFillColor(sf::Color(128, 0, 128, 255));
	Triangle.setPosition(ViewSize.x / 2, ViewSize.y / 2);
	//Triangle.setOrigin(sf::Vector2f(50, -50));

	Rectangle.setFillColor(sf::Color::Yellow);
	Rectangle.setPosition(ViewSize.x/2, ViewSize.y/2); // puts the rectangle in the mittle of the window
	//Rectangle.setPosition(0, 0); // sets the rectangle in the point 0 0 top Left corner
	// seting the origin to the center of the rectangle:
	Rectangle.setOrigin(sf::Vector2f(Rectangle.getSize().x/2, Rectangle.getSize().y/2));
	// sets the origin to the left corner of the rectangle
	//Rectangle.setOrigin(sf::Vector2f(0, 0));
	
	
	// Game loop will begin here
	while (Window.isOpen())
	{
		//Handle Keyboard Events
		
		//Upadte Game Objects in the sene
		Window.clear(sf::Color::Red);

		//renderGame Objects
		//here we call the objects
		Window.draw(Rectangle);
		Window.draw(Circle);
		Window.draw(Triangle);
		Window.display();
	}
	return 0;
}