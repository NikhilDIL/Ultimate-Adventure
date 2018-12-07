#include "Alexander.h"

Alexander::Alexander() {}

Alexander::Alexander(int x, int y, char t) {
	xCoord = x;
	yCoord = y;
	type = t;
	setAttack(15);
	setDefense(0);
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
	if (special_attack_active) {
		if (made_action) { // if character has already made a move this turn
			return -1;
		}
		else {
			made_action = true;
		}
		int strong_attack = getAttack() + 20;
		special_attack_active = false;
		return strong_attack;
	}
	else {
		return -1; // StrongAttack has already been made once over the course of the game
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