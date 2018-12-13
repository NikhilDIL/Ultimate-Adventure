#include "GameEngine.h"

GameEngine::GameEngine() {}

GameEngine::GameEngine(const std::vector<Character*> &characters) {
	character_list = characters; // add in characters to character_list

	// initialize battlefield 2d array to nullptrs
	for (int i = 0; i < kRowSize; i++) {
		for (int j = 0; j < kColSize; j++) {
			battlefield[i][j] = nullptr;
		}
	}

	// add characters from the character_list to the battlefield
	for (Character* character : character_list) {
		int r = character->GetRow();
		int c = character->GetCol();
		battlefield[r][c] = character;
	}

	SetUpBlockedLocations(); // sets up blocked locations on the map
}

GameEngine::~GameEngine() {}

bool GameEngine::IsValidMove(Direction direction, int character_index) {
	// CHECK IF CHARACTER HAS ANY MOVES LEFT FOR THE TURN.
	// get current row and column location of character
	int curr_row = character_list[character_index]->GetRow();
	int curr_col = character_list[character_index]->GetCol();

	switch (direction) {
		case RIGHT:
			curr_col++;
			break;
		case LEFT:
			curr_col--;
			break;
		case DOWN:
			curr_row++;
			break;
		case UP:
			curr_row--;
			break;
	}

	// check if out of bounds
	if ((curr_row >= kRowSize) || (curr_row < 0)) {
		return false;
	} else if ((curr_col >= kColSize) || (curr_col < 0)) {
		return false;
	}
	// if there's a character or obstacle at that location, return false.
	if (battlefield[curr_row][curr_col] != nullptr) {
		return false;
	} else if (IsBlockedLocation(curr_row, curr_col)) { // if there's a obstacle in that position, return false
		return false;
	}
	return true;
}


// Check if the following move can be made in the game engine board
// If that move can be made then do the move and return true
// else just return false
bool GameEngine::MoveCharacter(int direction, int character_index) {
	int curr_row = character_list[character_index]->GetRow();
	int curr_col = character_list[character_index]->GetCol();
	int val = 0;

	// update the location of character in battlefield
	switch (direction) {
		case RIGHT:
			val = curr_col + 1;
			character_list[character_index]->SetCol(val);
			battlefield[curr_row][val] = battlefield[curr_row][curr_col];
			break;
		case LEFT:
			val = curr_col - 1;
			character_list[character_index]->SetCol(val);
			battlefield[curr_row][val] = battlefield[curr_row][curr_col];
			break;
		case DOWN: 
			val = curr_row + 1;
			character_list[character_index]->SetRow(val);
			battlefield[val][curr_col] = battlefield[curr_row][curr_col];
			break;
		case UP: 
			val = curr_row - 1;
			character_list[character_index]->SetRow(val);
			battlefield[val][curr_col] = battlefield[curr_row][curr_col];
			break;
	}
	battlefield[curr_row][curr_col] = nullptr; // set old location to nullptr

	return true;
}

bool GameEngine::IsValidAttack(int attack_x, int attack_y, int victim_x, int victim_y, int character_range) {
	// x is row, y is col
	int a = (attack_x - victim_x) * (attack_x - victim_x);
	int b = (attack_y - victim_y) * (attack_y - victim_y);
	int distance = sqrt(a + b);
	if ((distance <= battlefield[attack_x][attack_y]->GetAttackRange()) && !(distance <= 0)) {
		return true;
	}
	return false;
}

bool GameEngine::ConductBattle(int attack_x, int attack_y, int victim_x, int victim_y, bool is_strong_attack) {
	// check if the victim of battle is within the range of attacker
	// if it's within the range, deal damage to said victim based on the attacker's attack power
	if (IsValidAttack(attack_x, attack_y, victim_x, victim_y, 1)) {
		// deal damage to the victim
		int damage = 0;
		if (is_strong_attack) {
			damage = battlefield[attack_x][attack_y]->StrongAttack();
		} else {
			damage = battlefield[attack_x][attack_y]->Attack();
		}

		if (damage == -1) { // player has already made an action this turn
			return false;
		}
		int victim_health = battlefield[victim_x][victim_y]->GetHealth();
		int victim_defense = battlefield[victim_x][victim_y]->GetDefense();
		if (victim_defense >= damage) { // if defense is greater than damage, then no damage is done
			return true;
		}
		int new_health = victim_health - damage;
		battlefield[victim_x][victim_y]->SetHealth(new_health);

		return true;
	}

	return false; // return false if battle was not successful
}

void GameEngine::RemoveCharacter(int x, int y, int character_index) {
	battlefield[x][y] = nullptr;
	character_list[character_index] = nullptr;
}


void GameEngine::SetUpBlockedLocations() {
	// initialize vector to instances of XYLocation struct
	for (int i = 0; i < 8; i++) { 
		blocked_locations.push_back(XYLocation());
	}

	int row_number = 6;
	int col_number = 0;
	for (int i = 0; i < 4; i++) {
		blocked_locations[i].row_pos = row_number;
		blocked_locations[i].col_pos = col_number;
		col_number++;
		if (i % 2 == 0) {
			row_number++;
		} else {
			row_number--;
		}
	}

	row_number = 4;
	col_number = 6;
	for (int i = 4; i < 8; i++) {
		blocked_locations[i].row_pos = row_number;
		blocked_locations[i].col_pos = col_number;
		col_number++;
		if (i % 2 == 0) {
			row_number--;
		} else {
			row_number++;
		}
	}
}

bool GameEngine::IsBlockedLocation(int r, int c) {
	for (XYLocation location : blocked_locations) {
		if ((location.col_pos == c) && (location.row_pos == r)) {
			return true;
		}
	}
	return false;
}
