#pragma once
#include "GameObject.h"
#include "tDirection.h"
#include "Bullet.h"
class Player :
	public GameObject
{
private:
	int health;
	tDirection direction;
	float speed;
	float dx, dy;
	bool shoot;
public:
	Player(String Name, float X, float Y, int W, int H, tDirection d);
	void move(tDirection d, float time);
	void update(float time);
	void setShooting(bool s);
	bool shooting();
	tDirection getDirection() {
		return direction;
	}
	~Player();
};

