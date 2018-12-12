#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Alexander.h"
#include "Direction.h"
#include "XYLocation.h"

using std::cout;
using std::endl;

class GameEngine {
private:
	const int kRowSize = 10; // row size of board
	const int kColSize = 10; // column size of board
	Character* battlefield[10][10]; // 10x10 grid where the fighting will take place
	std::vector<Character*> character_list; // list of all heroes on the board
	std::vector<XYLocation> blocked_locations; // list of blocked locations on the board

public:
	GameEngine(); // constructor
	~GameEngine(); // destructor
	GameEngine(const std::vector<Character*> &characters); // takes in a character array and initializes battlefield with characters
	void MoveCharacters(); // function to move the characters on the board
	bool MoveCharacter(int direction, int character_index); // move a single character on the board.
	bool IsValidMove(Direction direction, int character_index); // check if the move in that direction is valid
	bool IsValidAttack(int attack_x, int attack_y, int victim_x, int victim_y, int character_range); // method that checks if a battle between two units can occur
	bool ConductBattle(int attack_x, int attack_y, int victim_x, int victim_y, bool is_strong_attack); // conducts battle between two characters
	void RemoveCharacter(int x, int y, int character_index); // removes character from battle field. used when character dies
	void SetUpBlockedLocations(); // sets up blocked locations on the map
};
