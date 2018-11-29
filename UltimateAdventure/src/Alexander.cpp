#include "Alexander.h"

Alexander::Alexander() {
	xCoord = 200;
	yCoord = 675;
	steps_per_turn = 2;
}

Alexander::Alexander(int x, int y) {
	xCoord = x;
	yCoord = y;
	steps_per_turn = 2;
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
	image.resize(25, 25);
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
			xCoord += 25;
			break;
		case LEFT: // move left
			xCoord -= 25;
			break;
		case DOWN: // move down
			yCoord += 25;
			break;
		case UP: // move up
			yCoord -= 25;
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
