#include "Alexander.h"

Alexander::Alexander() {}

Alexander::Alexander(int x, int y, char t) {
	xCoord = x;
	yCoord = y;
	type = t;
}

int Alexander::Attack() {
	return 15;
}

void Alexander::Defend() {
	cout << "doge defend" << endl;
}

void Alexander::StrongAttack() {
	cout << "doge strong attack" << endl;
}

void Alexander::SpecialSkill() {
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

char Alexander::GetType() {
	return type;
}