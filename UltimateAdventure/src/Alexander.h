#pragma once
#include "ofMain.h"
#include "Warrior.h"
#include "Direction.h"

class Warrior;
class Alexander : public Warrior {
private:
	int xCoord;
	int yCoord;

public:
	Alexander(); // default constructor
	Alexander(int x, int y);
	void FirstSpecialSkill();
	void SecondSpecialSkill();
	void setup();
	void Draw();
	void SetUp();
	void draw();
	void update();
	void SetDirection(Direction direction);
	std::string GetName();
	ofImage image;
};