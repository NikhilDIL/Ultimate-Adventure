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
	int x_coord; // graphical x position
	int y_coord; // graphical y position
	char type; // type of the character H or E. H is Hero, E is Enemy
	int attack_power;
	int defense_power;
	int steps_per_turn;
	int attack_range;
	bool made_action = false; // has character attacked or defended this turn
	bool special_skill_active = true;
	bool special_attack_active = true;

public:
	Character(); // default constructor
	// All common among all unit classes
	virtual int Attack() = 0; // basic character attack
	virtual void Defend() = 0; // basic character defense
	virtual int StrongAttack() = 0; // stronger version of attack
	virtual void SpecialSkill() = 0; // character's special skill which gives them buffs
	virtual void Draw() = 0; // draw character on the field
	virtual void SetUp() = 0; // setup character
	virtual std::string GetName() = 0; // returns name of character
	virtual void ResetCharacter() = 0; // reset the character
	virtual void DisplayInformation(int x, int y) = 0; // display information of a character

	int GetStepsPerTurn(); // returns number of steps a character can make during a turn
	void DecrementStepsPerTurn(); // decreases the number of steps per tun by 1

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

	int GetAttackRange();
};
