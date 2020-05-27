#include "SFML/Graphics.hpp"

// windwo size variable
sf::Vector2f ViewSize(1024, 768);
sf::VideoMode ViewMode(ViewSize.x, ViewSize.y);
sf::RenderWindow Window(ViewMode, "Hello SFML Game!!", sf::Style::Default);

int main()
{
	// Initialize Game Objects:
	// test rectangle:
	sf::RectangleShape Rectangle(sf::Vector2f(500.0f, 300.0f));

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
		Window.display();
	}
	return 0;
}