#include <SFML/Graphics.hpp>
#include <ctime>

int main() {

	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");

	while (window.isOpen())
	{
		window.display();
	}
}