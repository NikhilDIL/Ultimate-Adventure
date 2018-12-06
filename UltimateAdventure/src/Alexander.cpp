#include "Alexander.h"

Alexander::Alexander() {}

Alexander::Alexander(int x, int y, char t) {
	xCoord = x;
	yCoord = y;
	type = t;
}

int Alexander::Attack() {
	if (made_action) { // if character has already made a move this turn
		return -1;
	}
	else {
		made_action = true;
	}
	return 15;
}

void Alexander::Defend() {
	made_action = true;
	cout << "doge defend" << endl;
}

void Alexander::StrongAttack() {
	made_action = true;
	cout << "doge strong attack" << endl;
}

void Alexander::SpecialSkill() {
	made_action = true;
	cout << "Hello World. I'm Alexander!" << endl;
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
	steps_per_turn = 3;
	made_action = false;
}