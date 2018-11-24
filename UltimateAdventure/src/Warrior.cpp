#include "Warrior.h"

Warrior::Warrior() {
}

Warrior::Warrior(int h, int x, int y) : health(h), locationX(x), locationY(y) {
}

void Warrior::Attack() {
	cout << "doge attack" << endl;
}

void Warrior::Defend() {
	cout << "doge defend" << endl;
}

void Warrior::StrongAttack() {
	cout << "doge strong attack" << endl;
}
