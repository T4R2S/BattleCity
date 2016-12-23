#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class GameObject {
protected:
	float x, y; //object coordinates
	int spriteHeight, spriteWidth; //sprite size
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
	int getSpriteHeight() {
		return spriteHeight;
	}
	int getSpriteWidth() {
		return spriteWidth;
	}
	void setExistance(bool e) {
		existance = e;
	}
	bool exists() {
		return existance;
	}
	GameObject(String Name, float X, float Y, int W, int H);
	void update(float time);
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	String getName() {
		return name;
	}
	~GameObject();
};

