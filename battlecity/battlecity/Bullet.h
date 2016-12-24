#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "tDirection.h"
#include "TextureManager.h"
#include <iostream>

using namespace sf;

class Bullet :
	public GameObject {
protected:
	int damage;
	tDirection direction;
	float speed;
	float dx, dy;
public:
	Bullet(String Name, float X, float Y, int W, int H, tDirection direct);
	void update(float time);
	int makeDamage() {
		return damage;
	}
	~Bullet();
};

