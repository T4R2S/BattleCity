#include "GameManager.h"
#include <sstream>


const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 

						 
String TileMap[HEIGHT_MAP] = {
"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
"S                                      S",
"S                                      S",
"S                                      S",
"S              00                      S",
"S                                      S",
"S                 0                    S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S             000000000                S",
"S             0000                     S",
"S             0000                     S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"S                                      S",
"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
};

GameManager::GameManager() {
	windowHeight = 480;
	windowWidth = 640;

}

void GameManager::play() {
	RenderWindow window(VideoMode(windowWidth, windowHeight), "test");

	TextureManager tm;
	Texture texture;
	Sprite sprite;
	texture = tm.getMainTexture();
	sprite.setTexture(texture);

	Player p("player1", 120, 120, windowWidth, windowHeight, up, sprite);
	Level lv(HEIGHT_MAP, WIDTH_MAP, TileMap, sprite);

	
	
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::White);
	text.setStyle(Text::Bold);

	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Event event;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		
		std::ostringstream gametime;    //std::cout << time << std::endl; 
		
		gametime << time;		
		text.setString("Время игры: " + gametime.str());

		text.setPosition(windowWidth-400, windowHeight-60);
		

		
		while (window.pollEvent(event)) {
			window.setKeyRepeatEnabled(false);
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					if (p.shooting()) {
						p.setShooting(false);
						bullets.push_back(new Bullet("PlayerBullet", p.getX() + 5, p.getY() + 5, windowWidth, windowHeight, p.getDirection(), sprite));
					}
				}
			}
		}
		update(p, lv);
		window.clear(Color(0, 0, 0, 255));
		for (bIterator = bullets.begin(); bIterator != bullets.end(); bIterator++) {
			window.draw((*bIterator)->getSprite());
		}

		lv.Draw(window);
		window.draw(p.getSprite());
		window.draw(text);
		window.display();
	}
}

void GameManager::update(Player &p, Level &lv) {
	p.update(time, lv);
	bIterator = bullets.begin();
	while (bIterator != bullets.end()) {
		if (((*bIterator)->getX() > windowWidth) || ((*bIterator)->getX() < 0) || ((*bIterator)->getY() < 0) || ((*bIterator)->getY() > windowHeight)) 
		{
			(*bIterator)->setExistance(false);
		}

		if ((*bIterator)->exists()) {
			if ((*bIterator)->getName() == "PlayerBullet") {
				//Выставить задержку на следующий выстрел
			}
			(*bIterator)->update(time, lv);
			bIterator++;
		}
		else {
			bIterator = bullets.erase(bIterator);
		}
	}
}





GameManager::~GameManager()
{
}
