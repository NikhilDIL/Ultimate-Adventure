#pragma once
#include "ofMain.h"
#include "Character.h"
#include "Direction.h"

class Alexander : public Character {
private:
	int xCoord;
	int yCoord;
	int steps_per_turn;

public:
	Alexander(); // default constructor
	Alexander(int x, int y);
	int Attack();
	void Defend();
	void StrongAttack();
	void SpecialSkill();

	void SetUp();
	void setup();
	void Draw();
	void draw();
	void update();
	void SetDirection(Direction direction);
	std::string GetName();
	int GetStepsPerTurn();

	int getGraphicalX();
	int getGraphicalY();


	ofImage image;
};