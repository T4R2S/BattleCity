#pragma once
#include "SFML\Graphics.hpp"
#include "TextureManager.h"
using namespace sf;

class LevelBuilder
{
private:
	Texture texture; //object texture
	Sprite map; //object sprite
public:
	LevelBuilder(float W, float H);
	~LevelBuilder();
	void Draw(sf::RenderWindow &window);
};

