#include "GameEngine.h"

GameEngine::GameEngine() {
	std::cout << "doge " << std::endl;
}

GameEngine::GameEngine(const std::vector<Character*> &characters) {
	std::cout << "Vector Constructor Called!" << std::endl;
	for (Character* character : characters) {
		character_list.push_back(character);
		cout << "char row: " << character_list[0]->getRow() << endl;
	}
	cout << character_list.size() << endl;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			battlefield[i][j] = nullptr;
		}
	}
	battlefield[0][0] = character_list[0];
	//battlefield[0][0]->FirstSpecialSkill();
	//battlefield[0][0]->SecondSpecialSkill();
}

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
		case RIGHT: // move right
			currCol++;
			break;
		case LEFT: // move left
			currCol--;
			break;
		case DOWN: // move down
			currRow++;
			break;
		case UP: // move up
			currRow--;
			break;
	}

	if ((currRow >= 25) || (currRow < 0)) {
		return false;
	}
	else if ((currCol >= 25) || (currCol < 0)) {
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

	switch (direction) {
		case RIGHT: // move right
			val = currCol + 1;
			character_list[character_index]->setCol(val);
			break;
		case LEFT: // move left
			val = currCol - 1;
			character_list[character_index]->setCol(val);
			break;
		case DOWN: // move down
			val = currRow + 1;
			character_list[character_index]->setRow(val);
			break;
		case UP: // move up
			val = currRow - 1;
			character_list[character_index]->setRow(val);
			break;
	}
	return true;
}