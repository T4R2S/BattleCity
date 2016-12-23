#include "Player.h"
#include "TextureManager.h"
#include <iostream>
#include "GameManager.h"


Player::Player(String Name, float X, float Y, int W, int H, tDirection d) : GameObject(Name, X, Y, W, H) {
	TextureManager tm(W, H);
	direction = d;
	speed = 0.1;
	shoot = false;
	texture = tm.getMainTexture();
	sprite.setTexture(texture);
	switch (direction) {
	case up:
		sprite.setTextureRect(IntRect(0, 0, 16, 16));
		break;
	case down:
		sprite.setTextureRect(IntRect(80, 0, 16, 16));
		break;
	case left:
		sprite.setTextureRect(IntRect(48, 0, 16, 16));
		break;
	case right:
		sprite.setTextureRect(IntRect(112, 0, 16, 16));
		break;
	}
}

void Player::move(tDirection d, float time) {
	direction = d;
	switch (direction) {
	case up:
		sprite.setTextureRect(IntRect(0, 0, 16, 16));
		dy = -speed;
		dx = 0;
		x += dx*time;
		y += dy*time;
		break;
	case down:
		sprite.setTextureRect(IntRect(80, 0, 16, 16));
		dy = speed;
		dx = 0;
		x += dx*time;
		y += dy*time;
		break;
	case left:
		sprite.setTextureRect(IntRect(48, 0, 16, 16));
		dx = -speed;
		dy = 0;
		x += dx*time;
		y += dy*time;
		break;
	case right:
		sprite.setTextureRect(IntRect(112, 0, 16, 16));
		dx = speed;
		dy = 0;
		x += dx*time;
		y += dy*time;
		break;
	}
}

void Player::update(float time) {
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		move(left, time);
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		move(right, time);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		move(up, time);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		move(down, time);
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		shoot = true;
	}
	sprite.setPosition(x, y);
}

void Player::setShooting(bool s) {
	shoot = s;
}

bool Player::shooting()
{
	return shoot;
}


Player::~Player()
{
}
