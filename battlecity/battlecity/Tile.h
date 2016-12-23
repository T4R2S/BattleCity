#pragma once
#include "GameObject.h"
class Tile :
	public GameObject
{
private:
	int health;
public:
	Tile(String Name, float X, float Y, int W, int H);
	~Tile();
};

