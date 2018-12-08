#pragma once
#include <iostream>
#include <string>
#include "Direction.h"
class Character {
private:
	int row;
	int col;
	int health;
	int attack_power;
	int defense_power;

public:
	Character(); // constructor
	// All common among all unit classes
	virtual int Attack() = 0;
	virtual void Defend() = 0;
	virtual int StrongAttack() = 0;
	virtual void SetDirection(Direction direction) = 0;
	virtual void Draw() = 0;
	virtual void SetUp() = 0;
	virtual std::string GetName() = 0; // returns name of character
	virtual char GetType() = 0; // Hero or Enemy type
	virtual int GetStepsPerTurn() = 0;
	virtual void DecrementStepsPerTurn() = 0;
	virtual void ResetCharacter() = 0;
	virtual void DisplayInformation(int x, int y) = 0;

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

	// Getter and setter functions for attack and defense
	void setAttack(int a);
	int getAttack();
	void setDefense(int d);
	int getDefense();
};
