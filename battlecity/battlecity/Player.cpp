#include "Player.h"
#include "TextureManager.h"
#include <iostream>
#include <stdlib.h>
#include "GameManager.h"


Player::Player(String Name, float X, float Y, int W, int H, tDirection d) : GameObject(Name, X, Y, W, H) {
	TextureManager tm;
	direction = d;
	speed = 0.1;
	shoot = false;
	texture = tm.getMainTexture();
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 16, 16));
}

void Player::move(tDirection d, float time) {
	direction = d;
	switch (direction) {
	case up:
		sprite.setTextureRect(IntRect(0, 0, 16, 16));
		dy = -speed;
		dx = 0;
		break;
	case down:
		sprite.setTextureRect(IntRect(80, 0, 16, 16));
		dy = speed;
		dx = 0;
		break;
	case left:
		sprite.setTextureRect(IntRect(48, 0, 16, 16));
		dx = -speed;
		dy = 0;	
		break;
	case right:
		sprite.setTextureRect(IntRect(112, 0, 16, 16));
		dx = speed;
		dy = 0;	
		break;
	}

	x += dx*time;
	y += dy*time;

	//std::cout << x << " " << y << " \n";
}

void Player::update(float time, Level &lv) {
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		move(left, time);
	} else
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		move(right, time);
	} else
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		move(up, time);
	} else
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		move(down, time);
	} else
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		shoot = true;
	}
	checkCollision(lv);
	//GameObject::update(time, lv);
	int chX = x / 16;
	int chY = y / 16;
	//std::cout << "       PLAYER  " << chX << " " << chY << "\n";
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
