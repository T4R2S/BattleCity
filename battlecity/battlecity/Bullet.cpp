#include "Bullet.h"
#include "TextureManager.h"
#include <iostream>

Bullet::Bullet(String Name, float X, float Y, int W, int H, tDirection direct) : GameObject(Name, X, Y, W, H) {
	direction = direct;
	std::cout << direction << std::endl;
	speed = 0.6; //all bullets speed
	switch (direction) {
	case up:
		sprite.setTextureRect(IntRect(322, 101, 5, 6));
		dy = -speed;
		dx = 0;
		break;
	case down:
		sprite.setTextureRect(IntRect(388, 101, 5, 6));
		dy = speed;
		dx = 0;
		break;
	case left:
		sprite.setTextureRect(IntRect(329, 101, 6, 5));
		dy = 0;
		dx = -speed;
		break;
	case right:
		sprite.setTextureRect(IntRect(345, 101, 6, 5));
		dy = 0;
		dx = speed;
		break;
	}
	TextureManager tm(W, H);
	texture = tm.getMainTexture();
	sprite.setTexture(texture);
}

void Bullet::update(float time) {
	x += dx*time;
	y += dy*time;
	sprite.setPosition(x, y);
}

Bullet::~Bullet()
{
}
