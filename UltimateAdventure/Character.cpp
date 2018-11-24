#include "Character.h"

Character::Character() {}


int Character::getRow() {
	return row;
}

int Character::getCol() {
	return col;
}

void Character::setRow(int r) {
	row = r;
}

void Character::setCol(int c) {
	col = c;
}

void Character::setHealth(int h) {
	health = h;
}

int Character::getHealth() {
	return health;
}


