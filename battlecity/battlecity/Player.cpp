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
	sprite.setPosition(x, y);
	/*
	int chX = x/16;
	int chY = y/16;

	std::cout << chX << " " << chY << " \n";
	if (lv.at(chX,chY) =="0")
	{
		std::string t = lv.at( chX , chY);
		std::cout << "test:" << t << "\n";
	}*/
}

void Player::checkCollision(Level &lv)
{
	for (int i = y/16; i < (y + 16) / 16; i++)
		for (int j = x/16; j<(x + 16) / 16; j++)
		{
			if (lv.at(i, j) == "0")
			{
				std::cout << "              BRICK";
				if (dy > 0)
				{
					y = i * 16 - 16;//getSpriteHeight();//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
				}
				if (dy < 0)
				{
					y = i * 16 + 16;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
				}
				if (dx > 0)
				{
					x = j * 16 - 16;//getSpriteWidth();//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
				}
				if (dx < 0)
				{
					x = j * 16 + 16;//аналогично идем влево
				}
			}
		}
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
