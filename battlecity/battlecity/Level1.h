#pragma once
#include "SFML\Graphics.hpp"
#include "TextureManager.h"
#include <iostream>

class Level
{
private:
	int heightMap;
	int widhtMap;
	sf::String* tileMap;
	sf::Texture texture;
	sf::Sprite map;
public:
	Level(int h, int w, String* tm)
	{
		tileMap = new String[h];
		heightMap = h;
		widhtMap = w;
		for (int i = 0; i < h; i++)
		{
			tileMap[i] = tm[i];
		}
		TextureManager textMan;
		texture = textMan.getMainTexture();
		map.setTexture(texture);
	}

	~Level()
	{
		delete[] tileMap;
	}

	int getHeigthMap()
	{
		return heightMap;
	}

	int getWidthMap()
	{
		return widhtMap;
	}

	String at(int h,int w)
	{
		return tileMap[h][w];
	}

	void Draw(sf::RenderWindow &wind)
	{
		for (int i = 0; i < heightMap; i++)
			for (int j = 0; j < widhtMap; j++)
			{
				if (tileMap[i][j] == '0')  map.setTextureRect(IntRect(256, 0, 16, 16));
				if ((tileMap[i][j] == ' ')) map.setTextureRect(IntRect(340, 0, 16, 16));

				map.setPosition(j * 16, i * 16);

				wind.draw(map);
			}
	}
};