#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1100, 925), "L_03");

	//Image image;
	//image.loadFromFile("github.jpg");
	//image.createMaskFromColor(Color(0, 0, 0));

	Texture texture;
	//texture.loadFromImage(image);
	texture.loadFromFile("github.jpg");

	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}