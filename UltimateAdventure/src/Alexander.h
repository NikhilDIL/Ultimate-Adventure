#pragma once
#include "ofMain.h"
#include "Warrior.h"
#include "Direction.h"

class Warrior;
class Alexander : public Warrior {
private:
	int xCoord;
	int yCoord;
	int curr_direction;


public:
	Alexander(); // default constructor
	Alexander(int x, int y);
	void FirstSpecialSkill();
	void SecondSpecialSkill();
	void setup();
	void draw();
	void update();
	void SetDirection(Direction direction);
	ofImage image;
};