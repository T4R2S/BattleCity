#include "TextureManager.h"

TextureManager::TextureManager()
{
	sprites.loadFromFile("images/sprites.png");
	sprites.createMaskFromColor(Color(0,0,1));
	mainTexture.loadFromImage(sprites);
}

TextureManager::~TextureManager()
{
}
