#include "GameEngine.h"

GameEngine::GameEngine() {}

GameEngine::GameEngine(const std::vector<Character*> &characters) {
	character_list = characters; // add in characters to character_list

	// initialize battlefield 2d array to nullptrs
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			battlefield[i][j] = nullptr;
		}
	}

	// add characters from the character_list to the battlefield
	for (Character* character : character_list) {
		int r = character->getRow();
		int c = character->getCol();
		battlefield[r][c] = character;
	}
}

GameEngine::~GameEngine() {}

void GameEngine::MoveCharacters() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			// if character exists at that location, move the character
			if (battlefield[i][j] != nullptr) {
				std::cout << "Moved Character" << std::endl;
			}
		}
	}
}

bool GameEngine::IsValidMove(Direction direction, int character_index) {
	// get current row and column location of character
	int currRow = character_list[character_index]->getRow();
	int currCol = character_list[character_index]->getCol();

	switch (direction) {
		case RIGHT:
			currCol++;
			break;
		case LEFT:
			currCol--;
			break;
		case DOWN:
			currRow++;
			break;
		case UP:
			currRow--;
			break;
	}

	// check if out of bounds
	if ((currRow >= kRowSize) || (currRow < 0)) {
		return false;
	}
	else if ((currCol >= kColSize) || (currCol < 0)) {
		return false;
	}
	// if there's a character or obstacle at that location, return false.
	if (battlefield[currRow][currCol] != nullptr) {
		return false;
	}

	return true;
}


// Check if the following move can be made in the game engine board
// If that move can be made then do the move and return true
// else just return false
bool GameEngine::MoveCharacter(int direction, int character_index) {
	int currRow = character_list[character_index]->getRow();
	int currCol = character_list[character_index]->getCol();
	int val = 0;

	// update the location of character in battlefield
	switch (direction) {
		case RIGHT:
			val = currCol + 1;
			character_list[character_index]->setCol(val);
			battlefield[currRow][val] = battlefield[currRow][currCol];
			break;
		case LEFT:
			val = currCol - 1;
			character_list[character_index]->setCol(val);
			battlefield[currRow][val] = battlefield[currRow][currCol];
			break;
		case DOWN: 
			val = currRow + 1;
			character_list[character_index]->setRow(val);
			battlefield[val][currCol] = battlefield[currRow][currCol];
			break;
		case UP: 
			val = currRow - 1;
			character_list[character_index]->setRow(val);
			battlefield[val][currCol] = battlefield[currRow][currCol];
			break;
	}
	battlefield[currRow][currCol] = nullptr; // set old location to nullptr

	return true;
}

bool GameEngine::IsValidAttack(int attack_x, int attack_y, int victim_x, int victim_y, int character_range) {
	// x is row, y is col
	int front = attack_x - character_range;
	int back = attack_x + character_range;
	int left = attack_y - character_range;
	int right = attack_y + character_range;

	if (!(front >= 25) && !(front < 0)) {
		if (battlefield[victim_x][victim_y] == battlefield[front][attack_y]) {
			return true;
		}
	}
	else if (!(back >= 25) && !(back < 0)) {
		if (battlefield[victim_x][victim_y] == battlefield[back][attack_y]) {
			return true;
		}
	}
	else if (!(left >= 25) && !(left < 0)) {
		if (battlefield[victim_x][victim_y] == battlefield[attack_x][left]) {
			return true;
		}
	}
	else if (!(right >= 25) && !(right < 0)) {
		if (battlefield[victim_x][victim_y] == battlefield[attack_x][right]) {
			return true;
		}
	}

	return false;
}

bool GameEngine::ConductBattle(int attack_x, int attack_y, int victim_x, int victim_y) {
	// check if the victim of battle is within the range of attacker
	// if it's within the range, deal damage to said victim based on the attacker's attack power
	if (IsValidAttack(attack_x, attack_y, victim_x, victim_y, 1)) {
		// deal damage to the victim
		int damage = battlefield[attack_x][attack_y]->Attack();
		int victim_health = battlefield[victim_x][victim_y]->getHealth();
		int new_health = victim_health - damage;
		battlefield[victim_x][victim_y]->setHealth(new_health);

		if (battlefield[victim_x][victim_y]->getHealth() <= 0) {
			std::cout << "This man has been killed" << std::endl;
		}
		return true;
	}

	return false; // return false if battle was not successful
}