#include "GameObject.h"

GameObject::GameObject(String Name, float X, float Y, int W, int H) {
	windowWidth = W;
	windowHeight = H;
	x = X;
	y = Y;
	existance = true;
	name = Name;
	sprite.setPosition(x, y);
}

GameObject::~GameObject(){
}

void GameObject::update(float time, Level &lv) 
{
	checkCollision(lv);
	sprite.setPosition(x, y);
}

void GameObject::checkCollision(Level &lv)
{
	for (int i = y / 16; i < (y + 16) / 16; i++)
		for (int j = x / 16; j<(x + 16) / 16; j++)
		{
			if (lv.at(i, j) == "0" || lv.at(i,j) == "S")
			{
				std::cout << "BRICKorSTONE";
				if (dy > 0)
				{
					y = i * 16 - 16;//getSpriteHeight();//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
				}
				if (dy < 0)
				{
					y = i * 16 + 16;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
				}
				if (dx > 0)
				{
					x = j * 16 - 16;//getSpriteWidth();//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
				}
				if (dx < 0)
				{
					x = j * 16 + 16;//���������� ���� �����
				}
			}
		}
}