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

	if ((currRow >= kRowSize) || (currRow < 0)) {
		return false;
	}
	else if ((currCol >= kColSize) || (currCol < 0)) {
		return false;
	}
	// If there's a character or obstacle at that location, return false.
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
		case RIGHT: // move right
			val = currCol + 1;
			character_list[character_index]->setCol(val);
			battlefield[currRow][val] = battlefield[currRow][currCol];
			break;
		case LEFT: // move left
			val = currCol - 1;
			character_list[character_index]->setCol(val);
			battlefield[currRow][val] = battlefield[currRow][currCol];
			break;
		case DOWN: // move down
			val = currRow + 1;
			character_list[character_index]->setRow(val);
			battlefield[val][currCol] = battlefield[currRow][currCol];
			break;
		case UP: // move up
			val = currRow - 1;
			character_list[character_index]->setRow(val);
			battlefield[val][currCol] = battlefield[currRow][currCol];
			break;
	}
	battlefield[currRow][currCol] = nullptr; // set old location to nullptr

	return true;
}