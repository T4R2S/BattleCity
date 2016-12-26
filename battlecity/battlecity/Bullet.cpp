#include "Bullet.h"

Bullet::Bullet(String Name, float X, float Y, int W, int H, tDirection direct, Sprite &sprite) : GameObject(Name, X, Y, W, H, sprite) {
	direction = direct;
	std::cout << direction << std::endl;
	speed = 0.6; //all bullets speed
	cooldown = 300;  //Задержка выстрела
	Bullet::sprite = sprite;
	switch (direction) {
	case up:
		Bullet::sprite.setTextureRect(IntRect(322, 101, 6, 6));
		dy = -speed;
		dx = 0;
		break;
	case down:
		Bullet::sprite.setTextureRect(IntRect(338, 101, 6, 6));
		dy = speed;
		dx = 0;
		break;
	case left:
		Bullet::sprite.setTextureRect(IntRect(329, 101, 6, 6));
		dy = 0;
		dx = -speed;
		break;
	case right:
		Bullet::sprite.setTextureRect(IntRect(345, 101, 6, 6));
		dy = 0;
		dx = speed;
		break;
	}
	/*
	TextureManager tm;
	texture = tm.getMainTexture();
	sprite.setTexture(texture);*/
}


Bullet::~Bullet()
{
}


void Bullet::update(float time, Level &lv) {
	x += dx*time;
	y += dy*time;
	sprite.setPosition(x, y);
	checkCollision(lv);
	int chX = x / 16;
	int chY = y / 16;
	std::cout << "                BULLET          " << chX << " " << chY << "\n";
}

void Bullet::checkCollision(Level &lv)
{
	for (int i = (int)(y / 16); i < (y + 16) / 16; i++)
		for (int j = (int)(x / 16); j< (x + 16) / 16; j++)
		{
			
			if (lv.at(i, j) == "0")
			{ 
				lv.setTile(' ', i, j);
				std::cout << "HIT THE BRICK";
				setExistance(false);
			}

			if (lv.at(i, j) == "S")
			{
				std::cout << "HIT THE STONE";
				setExistance(false);
			}
			
		}
}
