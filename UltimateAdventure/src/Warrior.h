#pragma once
#include <iostream>
#include "GameEngine.h"
#include "Character.h"
using std::cout;
using std::endl;

class Warrior : public Character {
private:
	int health;
	int locationX;
	int locationY;
public:
	Warrior(); // default constructor
	Warrior(int h, int x, int y);

	void Attack();
	void Defend();
	void StrongAttack();
	virtual void FirstSpecialSkill() = 0;
	virtual void SecondSpecialSkill() = 0;

	int getLocationX();
	int getLocationY();
	void setLocationX(int x);
	void setLocationY(int y);
};