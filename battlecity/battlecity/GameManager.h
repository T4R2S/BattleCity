#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#include <list>
#include <iterator>
#include <vector>
#include "Bullet.h"
#include "Player.h"

class GameManager
{
private:
	Clock clock;
	float time;
	Window window;
	int windowHeight, windowWidth;
	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bIterator;
public:
	GameManager();
	void play();
	void update(Player &p);
	~GameManager();
};

