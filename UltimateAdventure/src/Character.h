#pragma once
#include <string>
#include "Direction.h"
class Character {
private:
	int row;
	int col;
	int health;
	int attack_power;

public:
	Character(); // constructor
	// All common among all unit classes
	virtual int Attack() = 0;
	virtual void Defend() = 0;
	virtual void StrongAttack() = 0;
	virtual void SetDirection(Direction direction) = 0;
	virtual void Draw() = 0;
	virtual void SetUp() = 0;
	virtual std::string GetName() = 0; // returns name of character
	virtual char GetType() = 0; // Hero or Enemy type

	// Pixel location of where that character is graphically
	virtual int getGraphicalX() = 0; 
	virtual int getGraphicalY() = 0;

	// This varies depending on character
	virtual void SpecialSkill() = 0;

	// Getter and setter functions for row and col
	void setRow(int r);
	void setCol(int c);
	int getRow();
	int getCol();

	// Getter and setter functions for health
	void setHealth(int h);
	int getHealth();
};
