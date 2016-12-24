#include "GameManager.h"


const int HEIGHT_MAP = 25;//размер карты высота
const int WIDTH_MAP = 40;//размер карты ширина 

						 
String TileMap[HEIGHT_MAP] = {
"0000000000000000000000000000000000000000",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0                                      0",
"0000000000000000000000000000000000000000",
};

GameManager::GameManager() {
	windowHeight = 480;
	windowWidth = 640;

}

void GameManager::play() {
	RenderWindow window(VideoMode(windowWidth, windowHeight), "test");
	Player p("player1", 120, 120, windowWidth, windowHeight, up);
	Level lv(HEIGHT_MAP, WIDTH_MAP, TileMap);
		
	window.setFramerateLimit(120);
	while (window.isOpen()) {
		Event event;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		std::cout << time << std::endl;
		while (window.pollEvent(event)) {
			window.setKeyRepeatEnabled(false);
			if (event.type == Event::Closed) {
				window.close();
			}
			if (p.shooting()) {
				p.setShooting(false);
				bullets.push_back(new Bullet("PlayerBullet", p.getX() + 5, p.getY() + 5, windowWidth, windowHeight, p.getDirection()));
			}
		}
		update(p, lv);
		window.clear(Color(0, 0, 0, 255));
		for (bIterator = bullets.begin(); bIterator != bullets.end(); bIterator++) {
			window.draw((*bIterator)->getSprite());
		}

		lv.Draw(window);
		window.draw(p.getSprite());
		window.display();
	}
}

void GameManager::update(Player &p, Level &lv) {
	p.update(time, lv);
	bIterator = bullets.begin();
	while (bIterator != bullets.end()) {
		if (((*bIterator)->getX() > windowWidth) || ((*bIterator)->getX() < 0) || ((*bIterator)->getY() < 0) || ((*bIterator)->getY() > windowHeight)) {
			(*bIterator)->setExistance(false);
		}
		if ((*bIterator)->exists()) {
			if ((*bIterator)->getName() == "PlayerBullet") {
				p.setShooting(false);
			}
			(*bIterator)->update(time);
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
