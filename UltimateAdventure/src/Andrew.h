#pragma once
#include <algorithm>
#include <vector>
#include "ofMain.h"
#include "Character.h"

class Andrew : public Character {
public:
	Andrew(); // default constructor
	Andrew(int x, int y, char t, int a, int d, int h, int s, int range);

	// Implementations of all the virtual functions
	int Attack();
	void Defend();
	int StrongAttack();
	void SpecialSkill();
	std::string GetName(); // returns name of character
	void DisplayInformation(int x, int y); // displays information about character
	void ResetCharacter(); // resets character. called at the start of a turn.
	void SetUp();
	void Draw();

	// openframeworks functions
	void setup();
	void draw();

	ofImage image; // picture of the character
	ofSoundPlayer attack; // sound played when character attacks
};
