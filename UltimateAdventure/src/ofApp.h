#pragma once
#pragma once
#include "ofMain.h"
#include "GameEngine.h"
#include "Character.h"
#include "Alexander.h"
#include "Direction.h"
#include "Button.h"

typedef enum {
	HERO_TURN = 0,
	ENEMY_TURN,
	GAME_OVER
} TeamTurn;

class ofApp : public ofBaseApp {
private:
	GameEngine *engine;
	std::vector<Character*> units;
	int current_character = -1; // character the player has selected to give commands to
	int selected_character = -1; // character of the opposing team
	bool is_successful_attack;

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

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofSoundPlayer background;
	ofImage ground;
	ofImage rock;
	ofTrueTypeFont phase;
};

