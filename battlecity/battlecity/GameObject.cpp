#include "GameObject.h"
#include "SFML/Graphics.hpp"

GameObject::GameObject(String Name, float X, float Y, int W, int H) {
	windowWidth = W;
	windowHeight = H;
	x = X;
	y = Y;
	existance = true;
	name = Name;
	sprite.setPosition(x, y);
}

void GameObject::update(float time){
}

GameObject::~GameObject(){
}
