#pragma once
#include "ofMain.h"
#include "Character.h"
#include "Direction.h"

class Alexander : public Character {
private:
	int xCoord;
	int yCoord;

public:
	Alexander(); // default constructor
	Alexander(int x, int y);
	void Attack();
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

	int getGraphicalX();
	int getGraphicalY();


	ofImage image;
};