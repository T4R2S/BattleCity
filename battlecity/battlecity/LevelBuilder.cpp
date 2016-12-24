#include "LevelBuilder.h"
#include "Level1.h"



LevelBuilder::LevelBuilder(float W, float H)
{
	TextureManager tm(W, H);
	texture = tm.getMainTexture();
	map.setTexture(texture);
}


LevelBuilder::~LevelBuilder()
{
}

void LevelBuilder::Draw(sf::RenderWindow &window)
{
	for(int i=0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == '0')  map.setTextureRect(IntRect(256, 0, 16, 16));
			if ((TileMap[i][j] == ' ')) map.setTextureRect(IntRect(340, 0, 16, 16));

			map.setPosition(j * 16, i * 16);

			window.draw(map);
		}
}