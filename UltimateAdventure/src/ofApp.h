#pragma once
#include "ofMain.h"
#include "GameEngine.h"
#include "Character.h"
#include "Alexander.h"
#include "Cayden.h"
#include "Andrew.h"
#include "Adrian.h"
#include "Khrone.h"
#include "Abbadon.h"
#include "Direction.h"
#include "Button.h"

typedef enum {
	HERO_TURN = 0,
	ENEMY_TURN,
	GAME_OVER
} TeamTurn;

class ofApp : public ofBaseApp {
private:
	// CORRECT VERSION
	GameEngine *engine;
	std::vector<Character*> units;
	int current_character; // character the player has selected to give commands to
	int selected_character; // character of the opposing team
	bool is_successful_attack;
	int total_heroes;
	int total_enemies;

	// all buttons in game
	Button attack_button;
	Button defense_button;
	Button special_skill;
	Button special_attack;
	Button pass_turn;

	TeamTurn turn; // current team's turn

	// My Helper Methods
	void InitButtons(); // initializes the buttons
	void InitHeroes(); // initializes the heroes
	void InitEnemies(); // initializes the enemies
	void ResetCharacters(TeamTurn turn); // resets characters depending on the turn
	void DrawInformationDisplayBox(int x, int y, char type); // displays character statistics
	void CharacterBattle(bool is_strong_attack); // conducts battle between two characters
	bool IsButtonPressed(int x, int y); // checks if a button was pressed
	void CheckCharactedClicked(int x, int y); // checks if a character was clicked
	void DrawRocks(); // draws rocks on the map
	void DrawAttackAnimation(int x, int y); // animation that occurs when unit is attacked
	void DrawTurnDisplay(); // shows which team's turn it is. heroes or enemies.

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	ofSoundPlayer background;
	ofImage ground;
	ofImage rock;
	ofTrueTypeFont phase;
};