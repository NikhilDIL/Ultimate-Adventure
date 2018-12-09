#pragma once
#include <algorithm>
#include <vector>
#include "ofMain.h"
#include "Character.h"
#include "Direction.h"

class Alexander : public Character {
private:
	int steps_per_turn = 3;

public:
	Alexander(); // default constructor
	Alexander(int x, int y, char t, int a, int d, int h);

	// Implementations of all the virtual functions
	int Attack();
	void Defend();
	int StrongAttack();
	void SpecialSkill();
	void SetDirection(Direction direction);
	std::string GetName();
	void DisplayInformation(int x, int y);
	int GetStepsPerTurn();
	void DecrementStepsPerTurn();
	void ResetCharacter();
	void SetUp();
	void Draw();
	
	// openframeworks functions
	void setup();
	void draw();
	void update();
	
	ofImage image; // picture of the character
};