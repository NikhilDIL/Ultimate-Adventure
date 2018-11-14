#pragma once

#include <iostream>
#include <vector>
#include "Character.h"

class GameEngine {
private:
	Character *battlefield[25][25]; // 25x25 grid where the fighting will take place
public:
	GameEngine(); // constructor
	GameEngine(std::vector<Character*> characters); // takes in a character array and initializes battlefield with characters
	void MoveCharacters(); // function to move the characters on the board
};
