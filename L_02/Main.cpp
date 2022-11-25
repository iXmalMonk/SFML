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

	float currentFrame = 0;

	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 600;

		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		if (Keyboard::isKeyPressed(Keyboard::W) or
			Keyboard::isKeyPressed(Keyboard::S) or
			Keyboard::isKeyPressed(Keyboard::A) or
			Keyboard::isKeyPressed(Keyboard::D))
		{
			currentFrame += 0.005 * time;
			if (currentFrame > 4)
				currentFrame = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			heroSprite.setTextureRect(IntRect(64 * int(currentFrame), 0, 64, 64));
			heroSprite.move(0, -0.1 * time);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			heroSprite.setTextureRect(IntRect(64 * int(currentFrame), 64*3, 64, 64));
			heroSprite.move(0, 0.1 * time);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			heroSprite.setTextureRect(IntRect(64 * int(currentFrame), 64 * 2, 64, 64));
			heroSprite.move(-0.1 * time, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			heroSprite.setTextureRect(IntRect(64 * int(currentFrame), 64, 64, 64));
			heroSprite.move(0.1 * time, 0);
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