#pragma once
#include <string>
#include "Direction.h"
class Character {
private:
	int row;
	int col;
	int health;
public:
	Character(); // constructor
	// All common among all unit classes
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void StrongAttack() = 0;
	virtual void SetDirection(Direction direction) = 0;
	virtual void Draw() = 0;
	virtual void SetUp() = 0;
	virtual std::string GetName() = 0; // returns name of character

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
