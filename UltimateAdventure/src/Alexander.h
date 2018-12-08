#pragma once
#include <algorithm>
#include <vector>
#include "ofMain.h"
#include "Character.h"
#include "Direction.h"

class Alexander : public Character {
private:
	int xCoord;
	int yCoord;
	char type;
	int steps_per_turn = 3;
	bool made_action = false; // has character attacked or defended this turn
	bool special_skill_active = true;
	bool special_attack_active = true;

public:
	Alexander(); // default constructor
	Alexander(int x, int y, char t, int a, int d);
	int Attack();
	void Defend();
	int StrongAttack();
	void SpecialSkill();
	char GetType();
	void DisplayInformation(int x, int y);

	void SetUp();
	void setup();
	void Draw();
	void draw();
	void update();
	void SetDirection(Direction direction);
	std::string GetName();
	int GetStepsPerTurn();
	void DecrementStepsPerTurn();
	void ResetCharacter();

	int getGraphicalX();
	int getGraphicalY();

	ofImage image;
};