#include "Character.h"

Character::Character() {}


int Character::GetRow() {
	return row;
}

int Character::GetCol() {
	return col;
}

void Character::SetRow(int r) {
	row = r;
}

void Character::SetCol(int c) {
	col = c;
}

void Character::SetHealth(int h) {
	std::cout << "defense_power: " << defense_power << std::endl;
	std::cout << "h: " << h << std::endl;
	health = h + defense_power;
}

int Character::GetHealth() {
	return health;
}

void Character::SetAttack(int a) {
	attack_power = a;
}
int Character::GetAttack() {
	return attack_power;
}

void Character::SetDefense(int d) {
	defense_power = d;
}

int Character::GetDefense() {
	return defense_power;
}

int Character::getGraphicalX() {
	return x_coord;
}

int Character::getGraphicalY() {
	return y_coord;
}

char Character::GetType() {
	return type;
}

void Character::SetDirection(Direction direction) {
	// If the move is valid on the game engine board, then do the move. else return.
	switch (direction) {
	case RIGHT: // move right
		x_coord += 50;
		break;
	case LEFT: // move left
		x_coord -= 50;
		break;
	case DOWN: // move down
		y_coord += 50;
		break;
	case UP: // move up
		y_coord -= 50;
		break;
	}
}

int Character::GetStepsPerTurn() {
	return steps_per_turn;
}

void Character::DecrementStepsPerTurn() {
	steps_per_turn--;
}

int Character::GetAttackRange() {
	return attack_range;
}

