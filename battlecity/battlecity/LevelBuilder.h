#pragma once
#include "TextureManager.h"
#include "SFML\Graphics.hpp"
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

