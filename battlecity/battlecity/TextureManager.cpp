#include "TextureManager.h"

TextureManager::TextureManager(int widthWindow, int heightWindow)
{
	sprites.loadFromFile("images/sprites.png");
	sprites.createMaskFromColor(Color(0,0,1));
	mainTexture.loadFromImage(sprites);
}

TextureManager::~TextureManager()
{
}
