#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
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
	units[0]->SetUp();
	units[1]->SetUp();
	units[2]->SetUp();

	InitButtons();
	phase.load("PhaseFont.ttf", 50);

	turn = HERO_TURN; // Hero's play first
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	// draw graphical battlefield
	ofSetColor(255, 255, 255);
	ground.load("stone.jpg");
	ground.resize(500, 500);
	ground.draw(200, 150);

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

	// display turn
	if (turn == HERO_TURN) {
		phase.drawString("HERO TURN", 260, 125);
	}
	else if (turn == ENEMY_TURN) {
		phase.drawString("ENEMY TURN", 235, 125);
	}

	// display character information
	if (current_character != -1) {
		DrawInformationDisplayBox(15, 180, units[current_character]->GetType());
		units[current_character]->DisplayInformation(20, 200);
	} 
	if (selected_character != -1) {
		DrawInformationDisplayBox(15, 400, units[selected_character]->GetType());
		units[selected_character]->DisplayInformation(20, 420);
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
			}
			else if (upper_key == 'A') {
				if (engine->IsValidMove(LEFT, current_character)) {
					units[current_character]->SetDirection(LEFT);
					engine->MoveCharacter(LEFT, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			}
			else if (upper_key == 'S') {
				if (engine->IsValidMove(DOWN, current_character)) {
					units[current_character]->SetDirection(DOWN);
					engine->MoveCharacter(DOWN, current_character);
					units[current_character]->DecrementStepsPerTurn();
				}
			}
			else if (upper_key == 'D') {
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
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (!IsButtonPressed(x, y)) {
		// CHARACTER PRESSED
		for (int i = 0; i < units.size(); i++) {
			if (units[i] != nullptr) {
				if (x <= (units[i]->getGraphicalX() + 50) && x >= units[i]->getGraphicalX()) {
					if (y <= (units[i]->getGraphicalY() + 50) && y >= units[i]->getGraphicalY()) {
						std::cout << "SELECTED A CHARACTER!" << std::endl;
						if (units[i]->GetType() == 'H' && turn == HERO_TURN) { // a player selected a hero on Hero turn
							current_character = i;
						}
						else if (units[i]->GetType() == 'E' && turn == ENEMY_TURN) { // a player selected a enemy on Enemy turn 
							current_character = i;
						}
						else { // if we are controlling a character, allow another character to be selected so we can attack/do things to it.
							selected_character = i;
						}

						break;
					}
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

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
	}
	else if (turn == ENEMY_TURN) {
		type = 'E';
	}
	else {
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
	}
	else {
		ofSetColor(255, 0, 0);
	}
	ofNoFill();
	ofDrawRectangle(x, y, 160, 215);
}

void ofApp::InitHeroes() {
	Character* character = new Alexander(200, 600, 'H', 15, 0, 50, 3);
	character->SetCol(0);
	character->SetRow(9);
	units.push_back(character);

	Character* character2 = new Alexander(250, 600, 'H', 20, 0, 70, 3);
	character2->SetCol(1);
	character2->SetRow(9);
	units.push_back(character2);
}

void ofApp::InitEnemies() {
	Character* character = new Alexander(350, 600, 'E', 15, 0, 50, 3);
	character->SetCol(3);
	character->SetRow(9);
	units.push_back(character);
}

void ofApp::CharacterBattle(bool is_strong_attack) {
	if (selected_character != -1) {
		// conduct battle between the current unit and the selected unit
		int attack_x = units[current_character]->GetRow();
		int attack_y = units[current_character]->GetCol();
		int victim_x = units[selected_character]->GetRow();
		int victim_y = units[selected_character]->GetCol();

		std::cout << "attack_x " << attack_x << std::endl;
		std::cout << "attack_y " << attack_y << std::endl;
		std::cout << "victim_x " << victim_x << std::endl;
		std::cout << "victim_y " << victim_y << std::endl;

		engine->ConductBattle(attack_x, attack_y, victim_x, victim_y, is_strong_attack);
		if (units[selected_character]->GetHealth() <= 0) { // if victim's health is <= 0, remove character from field
			delete units[selected_character]; // remove character from graphical
			units[selected_character] = nullptr;
			engine->RemoveCharacter(victim_x, victim_y, selected_character); // removes character from battlefield array
			selected_character = -1; // reset selected_character
		}
		// if ConductBattle was successful, do an animation graphically for the attack
		// if the victim happens to be killed in the battle, then remove them graphically and from the battlefield
	}
}

bool ofApp::IsButtonPressed(int x, int y) {
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
		}
		else {
			turn = HERO_TURN;
		}
		ResetCharacters(turn);
		return true;
	}

	return false;
}