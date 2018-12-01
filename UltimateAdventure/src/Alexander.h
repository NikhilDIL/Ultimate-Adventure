#pragma once
#include "ofMain.h"
#include "Character.h"
#include "Direction.h"

class Alexander : public Character {
private:
	int xCoord;
	int yCoord;
	char type;
	int steps_per_turn;

public:
	Alexander(); // default constructor
	Alexander(int x, int y, char t);
	int Attack();
	void Defend();
	void StrongAttack();
	void SpecialSkill();
	char GetType();

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