#pragma once
#include "Direction.h"
class Character {
private:
	int row;
	int col;
	int health;
public:
	Character();
	// All common among all unit classes
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void StrongAttack() = 0;
	virtual void SetDirection(Direction direction) = 0;
	virtual void Draw() = 0;
	virtual void SetUp() = 0;

	// These vary depending on the character
	virtual void FirstSpecialSkill() = 0;
	virtual void SecondSpecialSkill() = 0;

	// Getter and setter functions for row and col
	void setRow(int r);
	void setCol(int c);
	int getRow();
	int getCol();

	// Getter and setter functions for health
	void setHealth(int h);
	int getHealth();
};
