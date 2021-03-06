#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
#include <list>
#include <iterator>
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Control.h"
#include "Level1.h"
#include <iostream>

class GameManager
{
private:
	Clock clock;
	float time;
	Window window;
	float windowHeight, windowWidth;
	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bIterator;
public:
	GameManager();
	void play();
	void update(Player &p, Level &lv);
	~GameManager();
};

