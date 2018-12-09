#pragma once
#include <iostream>
#include <string>
#include "Direction.h"
class Character {
private:
	int row; // row position on 2d battlefield array
	int col; // col position on 2d battlefield array

protected:
	int health;
	int x_coord; // graphical x
	int y_coord; // graphical y
	char type;
	int attack_power;
	int defense_power;
	int steps_per_turn;
	bool made_action = false; // has character attacked or defended this turn
	bool special_skill_active = true;
	bool special_attack_active = true;

public:
	Character(); // default constructor
	// All common among all unit classes
	virtual int Attack() = 0;
	virtual void Defend() = 0;
	virtual int StrongAttack() = 0;
	virtual void SpecialSkill() = 0;
	virtual void Draw() = 0;
	virtual void SetUp() = 0;
	virtual std::string GetName() = 0; // returns name of character
	virtual void ResetCharacter() = 0;
	virtual void DisplayInformation(int x, int y) = 0;

	int GetStepsPerTurn();
	void DecrementStepsPerTurn();

	void SetDirection(Direction direction);
	char GetType(); // Hero or Enemy type

	// Pixel location of where that character is graphically
	int getGraphicalX(); 
	int getGraphicalY();

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
