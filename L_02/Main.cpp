#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "SFML");

	Image heroImage;
	heroImage.loadFromFile("images/hero.png");

	Texture heroTexture;
	heroTexture.loadFromImage(heroImage);

	Sprite heroSprite;
	heroSprite.setTexture(heroTexture);
	heroSprite.setTextureRect(IntRect(0, 0, 64, 64));
	heroSprite.setPosition(100, 100);

	Event event;

	Clock clock;
	float time;

	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 600;

		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			heroSprite.move(0, -0.1 * time);
			heroSprite.setTextureRect(IntRect(0, 0, 64, 64));
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			heroSprite.move(0, 0.1 * time);
			heroSprite.setTextureRect(IntRect(0, 64*3, 64, 64));
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			heroSprite.move(-0.1 * time, 0);
			heroSprite.setTextureRect(IntRect(0, 64*2, 64, 64));
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			heroSprite.move(0.1 * time, 0);
			heroSprite.setTextureRect(IntRect(0, 64, 64, 64));
		}

		if (Mouse::isButtonPressed(Mouse::Left))
			heroSprite.setColor(Color::Red);
		else
			heroSprite.setColor(Color::White);

		window.clear();
		window.draw(heroSprite);
		window.display();
	}

	return 0;
}