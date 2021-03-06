#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	current_character = -1; 
	selected_character = -1;
	is_successful_attack = false;
	total_heroes = 3;
	total_enemies = 3;
	// initialize heroes and enemies
	InitHeroes();
	InitEnemies();

	// create a new game engine
	GameEngine *gameengine = new GameEngine(units); 
	engine = gameengine;

	ofSetWindowTitle("Ultimate Adventure");
	background.load("prolouge.mp3");
	background.play();
	background.setLoop(true);
	for (Character* character : units) {
		character->SetUp();
	}

	InitButtons();
	phase.load("PhaseFont.ttf", 50);

	turn = HERO_TURN; // Hero's play first
}

//--------------------------------------------------------------
void ofApp::update() {
	// check if all enemies or heroes are killed
	if ((total_enemies == 0) || (total_heroes == 0)) {
		turn = GAME_OVER;
		current_character = -1;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (turn != GAME_OVER) {
		// draw graphical battlefield
		ofSetColor(255, 255, 255);
		ground.load("stone.jpg");
		ground.resize(500, 500);
		ground.draw(200, 150);
		DrawRocks();

		// draw units
		for (Character* character : units) {
			if (character != nullptr) {
				character->Draw();
			}
		}

		// draw buttons
		attack_button.draw();
		defense_button.draw();
		special_skill.draw();
		special_attack.draw();
		pass_turn.draw();

		DrawTurnDisplay(); // displays the current turn

		// display character information
		if (current_character != -1) {
			DrawInformationDisplayBox(15, 180, units[current_character]->GetType());
			units[current_character]->DisplayInformation(20, 200);
		}
		if (selected_character != -1) {
			DrawInformationDisplayBox(15, 400, units[selected_character]->GetType());
			units[selected_character]->DisplayInformation(20, 420);
		}

		// small animation whenever a character is attacked
		if (is_successful_attack) {
			if (selected_character != -1) {
				int x = units[selected_character]->getGraphicalX();
				int y = units[selected_character]->getGraphicalY();
				DrawAttackAnimation(x, y);
			}
		}
	} else {
		ofSetColor(255, 255, 255);
		DrawTurnDisplay();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	int upper_key = toupper(key);

	// first check if that move can be made. If it can be made then move. Else, don't move.
	// move character on graphical display and array
	if (current_character != -1) { // making sure player has selected a character
		if (units[current_character]->GetStepsPerTurn() > 0) { // given character cannot more more than these many steps.
			if (upper_key == 'W') {
				if (engine->IsValidMove(UP, current_character)) {
					units[current_character]->SetDirection(UP);
					engine->MoveCharacter(UP, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			} else if (upper_key == 'A') {
				if (engine->IsValidMove(LEFT, current_character)) {
					units[current_character]->SetDirection(LEFT);
					engine->MoveCharacter(LEFT, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			} else if (upper_key == 'S') {
				if (engine->IsValidMove(DOWN, current_character)) {
					units[current_character]->SetDirection(DOWN);
					engine->MoveCharacter(DOWN, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			} else if (upper_key == 'D') {
				if (engine->IsValidMove(RIGHT, current_character)) {
					units[current_character]->SetDirection(RIGHT);
					engine->MoveCharacter(RIGHT, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			}
			units[current_character]->Draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (!IsButtonPressed(x, y)) { // check if a button was clicked
		CheckCharactedClicked(x, y); // if a button was not clicked, then check if a character was clicked
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	is_successful_attack = false;
}


void ofApp::InitButtons() {
	attack_button = Button(725, 530, 50, 50);
	attack_button.setup("AttackButton");
	defense_button = Button(800, 530, 50, 50);
	defense_button.setup("DefenseButton");
	special_skill = Button(725, 600, 50, 50);
	special_skill.setup("SpecialSkill");
	special_attack = Button(800, 600, 50, 50);
	special_attack.setup("SpecialAttack");
	pass_turn = Button(735, 475, 100, 40);
	pass_turn.setup("PassTurn");
}

void ofApp::ResetCharacters(TeamTurn turn) {
	char type = '\0';
	if (turn == HERO_TURN) {
		type = 'H';
	} else if (turn == ENEMY_TURN) {
		type = 'E';
	} else {
		return;
	}

	for (Character* character : units) {
		if (character != nullptr && type == character->GetType()) {
			character->ResetCharacter();
		}	
	}
	current_character = -1;
	selected_character = -1;
}


void ofApp::DrawInformationDisplayBox(int x, int y, char type) {
	if (type == 'H') {
		ofSetColor(0, 153, 51);
	} else {
		ofSetColor(255, 0, 0);
	}
	ofNoFill();
	ofDrawRectangle(x, y, 160, 215);
}

void ofApp::InitHeroes() {
	Character* character = new Alexander(200, 600, 'H', 15, 0, 50, 3, 1);
	character->SetCol(0);
	character->SetRow(9);
	units.push_back(character);

	Character* character2 = new Cayden(250, 600, 'H', 10, 5, 60, 3, 1);
	character2->SetCol(1);
	character2->SetRow(9);
	units.push_back(character2);

	Character* character3 = new Andrew(300, 600, 'H', 15, 0, 40, 2, 3);
	character3->SetCol(2);
	character3->SetRow(9);
	units.push_back(character3);
}

void ofApp::InitEnemies() {
	Character* character = new Adrian(600, 150, 'E', 15, 0, 35, 2, 3);
	character->SetCol(8);
	character->SetRow(0);
	units.push_back(character);

	Character* character2 = new Khrone(550, 150, 'E', 15, 0, 50, 3, 1);
	character2->SetCol(7);
	character2->SetRow(0);
	units.push_back(character2);

	Character* character3 = new Abbadon(500, 150, 'E', 20, 0, 65, 3, 1);
	character3->SetCol(6);
	character3->SetRow(0);
	units.push_back(character3);
}

void ofApp::CharacterBattle(bool is_strong_attack) {
	if (selected_character != -1) {
		// conduct battle between the current unit and the selected unit
		int attack_x = units[current_character]->GetRow();
		int attack_y = units[current_character]->GetCol();
		int victim_x = units[selected_character]->GetRow();
		int victim_y = units[selected_character]->GetCol();

		if (engine->ConductBattle(attack_x, attack_y, victim_x, victim_y, is_strong_attack)) {
			is_successful_attack = true;
		}
		if (units[selected_character]->GetHealth() <= 0) { // if victim's health is <= 0, remove character from field
			if (units[selected_character]->GetType() == 'H') { // if the victim that was killed is a hero, decrement total_heroes
				total_heroes--;
			} else {
				total_enemies--;
			}
			delete units[selected_character]; // remove character from graphical
			units[selected_character] = nullptr;
			engine->RemoveCharacter(victim_x, victim_y, selected_character); // removes character from battlefield array
			selected_character = -1; // reset selected_character
		}
	}
}

bool ofApp::IsButtonPressed(int x, int y) {
	if (turn == GAME_OVER) {
		return false;
	}
	if (current_character != -1) {
		// BUTTON PRESSED
		if (attack_button.IsClicked(x, y)) {
			CharacterBattle(false);
			return true;
		}

		// DEFENSE BUTTON
		if (defense_button.IsClicked(x, y)) {
			units[current_character]->Defend();
			return true;
		}

		// SPECIAL SKILL BUTTON
		if (special_skill.IsClicked(x, y)) {
			units[current_character]->SpecialSkill();
			return true;
		}

		// SPECIAL ATTACK BUTTON
		if (special_attack.IsClicked(x, y)) {
			CharacterBattle(true);
			return true;
		}
	}

	// PASS TURN BUTTON
	if (pass_turn.IsClicked(x, y)) {
		if (turn == HERO_TURN) {
			turn = ENEMY_TURN;
		} else {
			turn = HERO_TURN;
		}
		ResetCharacters(turn);
		return true;
	}

	return false;
}

void ofApp::CheckCharactedClicked(int x, int y) {
	if (turn == GAME_OVER) {
		return;
	}
	// CHARACTER PRESSED
	for (int i = 0; i < units.size(); i++) {
		if (units[i] != nullptr) {
			if (x <= (units[i]->getGraphicalX() + 50) && x >= units[i]->getGraphicalX()) {
				if (y <= (units[i]->getGraphicalY() + 50) && y >= units[i]->getGraphicalY()) {
					if (units[i]->GetType() == 'H' && turn == HERO_TURN) { // a player selected a hero on Hero turn
						current_character = i;
					} else if (units[i]->GetType() == 'E' && turn == ENEMY_TURN) { // a player selected a enemy on Enemy turn 
						current_character = i;
					} else { // if we are controlling a character, allow another character to be selected so we can attack/do things to it.
						selected_character = i;
					}
					break;
				}
			}
		}
	}
}

void ofApp::DrawRocks() {
	rock.load("Rock.png");
	rock.resize(50, 50);
	int temp_var = 200;
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			rock.draw(temp_var, 450);
			temp_var += 50;
		} else {
			rock.draw(temp_var, 500);
			temp_var += 50;
		}
	}
	temp_var = 650;
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			rock.draw(temp_var, 300);
			temp_var -= 50;
		} else {
			rock.draw(temp_var, 350);
			temp_var -= 50;
		}
	}
}

void ofApp::DrawAttackAnimation(int x, int y) {
	ofSetColor(255, 0, 0);
	ofDrawRectangle(x, y, 50, 50);
}

void ofApp::DrawTurnDisplay() {
	if (turn == HERO_TURN) {
		phase.drawString("HERO TURN", 260, 125);
	}
	else if (turn == ENEMY_TURN) {
		phase.drawString("ENEMY TURN", 235, 125);
	}
	else {
		if (total_heroes > total_enemies) {
			phase.drawString("HEROES WIN!", 235, 300);
		}
		else {
			phase.drawString("ENEMIES WIN!", 215, 300);
		}
		for (int i = 0; i < units.size(); i++) {
			if (units[i] != nullptr) {
				delete units[i];
				units[i] = nullptr;
			}
		}
	}
}