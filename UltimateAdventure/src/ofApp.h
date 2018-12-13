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
	int current_character = -1; // character the player has selected to give commands to
	int selected_character = -1; // character of the opposing team
	bool is_successful_attack = false;

	// all buttons in game
	Button attack_button;
	Button defense_button;
	Button special_skill;
	Button special_attack;
	Button pass_turn;

	TeamTurn turn; // current team's turn

	// My Helper Methods
	void InitButtons();
	void InitHeroes();
	void InitEnemies();
	void ResetCharacters(TeamTurn turn);
	void DrawInformationDisplayBox(int x, int y, char type);
	void CharacterBattle(bool is_strong_attack);
	bool IsButtonPressed(int x, int y);
	void CheckCharactedClicked(int x, int y);
	void DrawRocks();
	void DrawAttackAnimation(int x, int y);

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