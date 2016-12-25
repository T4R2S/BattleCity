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
	bool shoot;
public:
	Player(String Name, float X, float Y, int W, int H, tDirection d);
	void move(tDirection d, float time);
	void update(float time, Level &lv);
	void setShooting(bool s);
	bool shooting();
	tDirection getDirection() {
		return direction;
	}
	~Player();
	float getDx()
	{
		return dx;
	}

	float getDy()
	{
		return dx;
	}

	void setY(float arg)
	{
		y = arg;
	}

	void setX(float arg)
	{
		x = arg;
	}

};

