#include "Alexander.h"

Alexander::Alexander() {}

Alexander::Alexander(int x, int y, char t, int a, int d) {
	xCoord = x;
	yCoord = y;
	type = t;
	setAttack(a);
	setDefense(d);
}

int Alexander::Attack() {
	if (made_action) { // if character has already made a move this turn
		return -1;
	}
	else {
		made_action = true;
	}
	return getAttack();
}

void Alexander::Defend() {
	if (made_action) { // if character has already made a move this turn
		return;
	}
	else {
		made_action = true;
	}
	setDefense(5);
}

int Alexander::StrongAttack() {
	if (made_action) { // if character has already made a move this turn
		return -1;
	}
	if (special_attack_active) {
		made_action = true;
		special_attack_active = false;
		int strong_attack = getAttack() + 20;
		return strong_attack;
	}
	else {
		return -1;
	}
}

void Alexander::SpecialSkill() { 
	if (special_skill_active) {
		int current_attack = getAttack();
		int new_attack = current_attack + 10;
		setAttack(new_attack);
		special_skill_active = false;
	}
}

void Alexander::setup() {
	image.load("randpic.png");
	image.resize(50, 50);
}

void Alexander::Draw() {
	draw();
}

void Alexander::SetUp() {
	setup();
}

void Alexander::draw() {
	image.draw(xCoord, yCoord);
}

void Alexander::update() {}

void Alexander::SetDirection(Direction direction) {
	// If the move is valid on the game engine board, then do the move. else return.
	switch (direction) { 
		case RIGHT: // move right
			xCoord += 50;
			break;
		case LEFT: // move left
			xCoord -= 50;
			break;
		case DOWN: // move down
			yCoord += 50;
			break;
		case UP: // move up
			yCoord -= 50;
			break;
	}
}

std::string Alexander::GetName() {
	return "Alexander";
}

int Alexander::getGraphicalX() {
	return xCoord;
}

int Alexander::getGraphicalY() {
	return yCoord;
}

int Alexander::GetStepsPerTurn() {
	return steps_per_turn;
}

void Alexander::DecrementStepsPerTurn() {
	steps_per_turn--;
}

char Alexander::GetType() {
	return type;
}

void Alexander::ResetCharacter() {
	// resets steps and any buffs from previous turn
	steps_per_turn = 3;
	made_action = false;
	setAttack(15);
	setDefense(0);
}

void Alexander::DisplayInformation(int x, int y) {
	int X = x;
	int Y = y;
	std::string name = GetName();
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	std::string health = "Health: " + to_string(getHealth());
	std::string attack = "Attack: " + to_string(getAttack());
	std::string defense = "Defense: " + to_string(getDefense());
	std::string special_skill = "Special Skill: (A)";
	if (!special_skill_active) {
		special_skill = "Special Skill: (U)";
	}
	special_skill = special_skill + "\nAttack +10";
	std::string strong_attack = "Strong Attack: (A)";
	if (!special_attack_active) {
		strong_attack = "Strong Attack: (U)";
	}
	strong_attack = strong_attack + "\nDeals 25 damage";

	std::vector<std::string> stats;
	stats.push_back(health);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(special_skill);
	stats.push_back(strong_attack);
		
	ofDrawBitmapString("   " + name, x, y);
	y += 15;
	for (std::string stat : stats) {
		ofDrawBitmapString(stat, x, y);
		y += 15;
		if (stat.compare(special_skill) == 0 || stat.compare(strong_attack) == 0) {
			y += 15;
		}
	}
}