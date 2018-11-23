#include "Alexander.h"

Alexander::Alexander() {
	xCoord = 250;
	yCoord = 150;
}

Alexander::Alexander(int x, int y) {
	xCoord = x;
	yCoord = y;
}

void Alexander::FirstSpecialSkill() {
	cout << "Hello World. I'm Alexander!" << endl;
}

void Alexander::SecondSpecialSkill() {
	cout << "Hello World. I'm Alexander!. Special Second!" << endl;
}

void Alexander::setup() {
	image.load("randpic.png");
	image.resize(50, 50);
}

void Alexander::draw() {
	image.draw(xCoord, yCoord);
}

void Alexander::update() {
	cout << "nothing" << endl;
}

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

