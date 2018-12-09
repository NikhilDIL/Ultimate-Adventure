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
	Character(); // default constructor
	// All common among all unit classes
	virtual int Attack() = 0;
	virtual void Defend() = 0;
	virtual int StrongAttack() = 0;
	virtual void SpecialSkill() = 0;
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

	// Getter and setter functions for row and col
	void SetRow(int r);
	void SetCol(int c);
	int GetRow();
	int GetCol();

	// Getter and setter functions for health, attack, and defense
	void SetHealth(int h);
	int GetHealth();
	void SetAttack(int a);
	int GetAttack();
	void SetDefense(int d);
	int GetDefense();
};
