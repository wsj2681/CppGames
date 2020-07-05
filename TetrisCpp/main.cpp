#include <SFML/Graphics.hpp>
#include <ctime>

const int Height{ 20 };
const int Width{ 10 };

int Field[Height][Width]{ 0, };

struct Point
{
	int x;
	int y;
}a[4], b[4];

int Figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

bool Check() {
	for (int i = 0; i < 4; ++i) {
		if (a[i].x || a[i].x >= Width || a[i].y >= Height)
			return false;
		else if (Field[a[i].y][a[i].x])
			return false;
	}
	return true;
}

int main() {

	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");

	sf::Texture Textiles, Texbackground, Texframe;
	Textiles.loadFromFile("images/tiles.png");
	Texbackground.loadFromFile("images/background.png");
	Texframe.loadFromFile("images/frame.png");

	sf::Sprite tile(Textiles), background(Texbackground), frame(Texframe);

	int dx{ 0 };

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		window.draw(background);
		window.draw(frame);
		window.display();
	}
}