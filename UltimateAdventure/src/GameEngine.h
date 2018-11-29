#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Alexander.h"
#include "Direction.h"

using std::cout;
using std::endl;

class GameEngine {
private:
	const int kRowSize = 25;
	const int kColSize = 25;
	Character* battlefield[25][25]; // 25x25 grid where the fighting will take place
	std::vector<Character*> character_list; // list of all heroes on the board

public:
	GameEngine(); // constructor
	~GameEngine(); // destructor
	GameEngine(const std::vector<Character*> &characters); // takes in a character array and initializes battlefield with characters
	void MoveCharacters(); // function to move the characters on the board
	bool MoveCharacter(int direction, int character_index); // move a single character on the board.
	bool IsValidMove(Direction direction, int character_index); // check if the move in that direction is valid
	bool IsValidAttack(int attack_x, int attack_y, int victim_x, int victim_y, int character_range); // method that checks if a battle between two units can occur
	bool ConductBattle(int attack_x, int attack_y, int victim_x, int victim_y); // conducts battle between two characters
};
