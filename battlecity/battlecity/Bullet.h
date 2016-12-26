#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "tDirection.h"
#include "TextureManager.h"
#include <iostream>

using namespace sf;

class Bullet :
	public GameObject {
private:
	Sprite sprite;
protected:
	int damage;
	tDirection direction;
	float speed;
	float cooldown; //Задержка выстрела
public:
	Bullet(String Name, float X, float Y, int W, int H, tDirection direct, Sprite &sprite);
	void update(float time, Level &lv);
	void checkCollision(Level &lv);
	float getCooldown()
	{
		return cooldown;
	}
	Sprite getSprite()
	{
		return sprite;
	}
	int makeDamage() {
		return damage;
	}
	~Bullet();
};

