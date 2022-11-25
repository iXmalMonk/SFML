#include <SFML/Graphics.hpp>

#include "Map.h"
#include "View.h"

using namespace sf;

#define WIDTH_WIN 640
#define HEIGHT_WIN 480

class Player
{
private:
	double x, y;
	int w, h;
	double dx = 0, dy = 0, speed = 0;
	int direction = 0;

	String file;
	Image image;
	Texture texture;
	Sprite sprite;

public:
	Player(double x, double y, int w, int h, String file)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;

		this->file = file;

		this->image.loadFromFile("images/" + this->file);
		this->texture.loadFromImage(this->image);
		this->sprite.setTexture(this->texture);
		this->sprite.setTextureRect(IntRect(this->x, this->y, this->w, this->h));
	}

	void setDirection(int direction)
	{
		this->direction = direction;
	}

	void setSpeed(double speed)
	{
		this->speed = speed;
	}

	void setTxtrRct(int direction, float currentFrame)
	{
		this->sprite.setTextureRect(IntRect(this->w * int(currentFrame), this->w * direction, this->w, this->h));
	}

	Sprite getSprite()
	{
		return this->sprite;
	}

	double getX()
	{
		return this->x;
	}

	double getY()
	{
		return this->y;
	}

	void update(float time)
	{
		switch (this->direction)
		{
		case 0:
			this->dx = this->speed;
			this->dy = 0;
			break;
		case 1:
			this->dx = -(this->speed);
			this->dy = 0;
			break;
		case 2:
			this->dx = 0;
			this->dy = this->speed;
			break;
		case 3:
			this->dx = 0;
			this->dy = -(this->speed);
			break;
		}

		this->x += this->dx * time;
		this->y += this->dy * time;

		this->speed = 0;

		this->sprite.setPosition(this->x, this->y);
		this->interactionWithMap();
	}

	void interactionWithMap()
	{
		for (int i = this->y / 32; i < (this->y + this->h) / 32; i++)
			for (int j = this->x / 32; j < (this->x + this->w) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if (this->dx > 0)
						this->x = j * 32 - this->w;
					if (this->dx < 0)
						this->x = j * 32 + 32;
					if (this->dy > 0)
						this->y = i * 32 - this->h;
					if (this->dy < 0)
						this->y = i * 32 + 32;
				}

				if (TileMap[i][j] == '1')
				{
					if (this->dx > 0)
						this->x = j * 32 - this->w;
					if (this->dx < 0)
						this->x = j * 32 + 32;
					if (this->dy > 0)
						this->y = i * 32 - this->h;
					if (this->dy < 0)
						this->y = i * 32 + 32;
				}
			}
	}
};

int main()
{
	RenderWindow window(VideoMode(WIDTH_WIN, HEIGHT_WIN), "SFML");

	view.reset(FloatRect(0, 0, WIDTH_WIN, HEIGHT_WIN));

	Event event;
	
	Clock clock;
	float time = 0;

	Player hero(600, 400, 64, 64, "hero.png");
	float currentFrame = 0;
	int maxFrame = 4;
	hero.update(time);

	// ------------------------------ MAP
	Image mapImg;
	mapImg.loadFromFile("images/map.png");
	Texture mapTxtr;
	mapTxtr.loadFromImage(mapImg);
	Sprite mapSprt;
	mapSprt.setTexture(mapTxtr);
	// ------------------------------ MAP

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
			if (currentFrame > maxFrame)
				currentFrame = 0;
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			hero.setDirection(3);
			hero.setSpeed(0.1);
			hero.setTxtrRct(0, currentFrame);

			hero.update(time);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			hero.setDirection(2);
			hero.setSpeed(0.1);
			hero.setTxtrRct(3, currentFrame);

			hero.update(time);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			hero.setDirection(1);
			hero.setSpeed(0.1);
			hero.setTxtrRct(2, currentFrame);

			hero.update(time);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			hero.setDirection(0);
			hero.setSpeed(0.1);
			hero.setTxtrRct(1, currentFrame);

			hero.update(time);
		}

		getPlayerCoordinateForView(hero.getX(), hero.getY());
		window.setView(view);

		window.clear();

		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ') mapSprt.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == '1') mapSprt.setTextureRect(IntRect(32, 0, 32, 32));
				if (TileMap[i][j] == '0') mapSprt.setTextureRect(IntRect(64, 0, 32, 32));

				mapSprt.setPosition(j * 32, i * 32);
				window.draw(mapSprt);
			}

		window.draw(hero.getSprite());
		window.display();
	}

	return 0;
}