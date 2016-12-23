#include "UnbreakableWall.h"
#include "TextureManager.h"


UnbreakableWall::UnbreakableWall(String Name, float X, float Y, int W, int H) : Tile (Name, X, Y, W, H)
{
	TextureManager tm(W, H);
	texture = tm.getMainTexture();
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(256, 16, 16, 16));
}


UnbreakableWall::~UnbreakableWall()
{
}
