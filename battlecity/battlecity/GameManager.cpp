#include "GameManager.h"
#include "LevelBuilder.h"
#include <iostream>


GameManager::GameManager() {
	windowHeight = 480;
	windowWidth = 640;

}

void GameManager::play() {
	RenderWindow window(VideoMode(windowWidth, windowHeight), "test");
	Player p("player1", 120, 120, windowWidth, windowHeight, up);
	LevelBuilder lv(windowWidth, windowHeight);
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
		update(p);
		window.clear(Color(0, 0, 0, 255));
		lv.Draw(window);
		for (bIterator = bullets.begin(); bIterator != bullets.end(); bIterator++) {
			window.draw((*bIterator)->getSprite());
		}
		window.draw(p.getSprite());
		window.display();
	}
}

void GameManager::update(Player &p) {
	p.update(time);
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
