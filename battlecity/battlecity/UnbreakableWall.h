#pragma once
#include "Tile.h"
class UnbreakableWall :
	public Tile
{
public:
	UnbreakableWall(String Name, float X, float Y, int W, int H);
	~UnbreakableWall();
};

