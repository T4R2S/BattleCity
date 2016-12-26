#pragma once
#include <SFML\Graphics.hpp>
#include "Level1.h"
using namespace sf;

class GameObject {
protected:
	float x, y; //object coordinates
	float dx, dy;
	float spriteHeight, spriteWidth; //sprite size
	bool existance; //check, if object exists
	int windowHeight, windowWidth; //window size
	Texture texture; //object texture
	Sprite sprite; //object sprite
	String name;
public:
	FloatRect getRect() {
		return FloatRect(x, y, spriteWidth, spriteHeight);
	}
	Sprite getSprite() {
		return sprite;
	}
	float getSpriteHeight() {
		return spriteHeight;
	}
	float getSpriteWidth() {
		return spriteWidth;
	}
	void setExistance(bool e) {
		existance = e;
	}
	bool exists() {
		return existance;
	}
	GameObject(String Name, float X, float Y, int W, int H, Sprite &sprite);
	void update(float time, Level &lv);

	void checkCollision(Level &lv);

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}
	String getName() {
		return name;
	}
	~GameObject();
};

