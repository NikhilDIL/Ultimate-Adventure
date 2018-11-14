#include "GameEngine.h"

GameEngine::GameEngine() {
	std::cout << "new game bro" << std::endl;
	// initialize the battlefield array to nullptr
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			battlefield[i][j] = nullptr;
		}
	}
}

GameEngine::GameEngine(std::vector<Character*> characters) {
	std::cout << "Vector Constructor Called!" << std::endl;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			battlefield[i][j] = nullptr;
		}
	}
	battlefield[0][0] = characters[0];
	battlefield[0][0]->FirstSpecialSkill();
	battlefield[0][0]->SecondSpecialSkill();
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