#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Warrior.h"
#include "Alexander.h"
#include "Direction.h"

using std::cout;
using std::endl;

class GameEngine {
private:
	Character* battlefield[25][25]; // 25x25 grid where the fighting will take place
	std::vector<Character*> character_list;
public:
	GameEngine(); // constructor
	~GameEngine(); // destructor
	GameEngine(const std::vector<Character*> &characters); // takes in a character array and initializes battlefield with characters
	void MoveCharacters(); // function to move the characters on the board
	bool MoveCharacter(int direction, int character_index); // move a single character on the board.
	bool IsValidMove(Direction direction, int character_index); // check if the move in that direction is valid
};
