#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class TextureManager
{
private:
	Image sprites;
	Texture mainTexture;
	Sprite bullet;
	Sprite player;
public:
	TextureManager();
	Texture getMainTexture() {
		return mainTexture;
	}
	~TextureManager();
};
