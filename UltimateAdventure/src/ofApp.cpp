#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	current_character;
	// create character and add it to the vector
	Alexander *obj = new Alexander(200, 600, 'H');
	Character* character = obj;
	character->setCol(0);
	character->setRow(9);
	character->setHealth(50);
	units.push_back(character);

	Alexander *obj2 = new Alexander(300, 600, 'E');
	Character* character2 = obj2;
	character2->setCol(2);
	character2->setRow(9);
	character2->setHealth(50);
	units.push_back(character2);

	// create a new game engine
	GameEngine *gameengine = new GameEngine(units); 
	engine = gameengine;

	ofSetWindowTitle("Ultimate Adventure");
	background.load("prolouge.mp3");
	background.play();
	background.setLoop(true);
	units[0]->SetUp();
	units[1]->SetUp();

	initButtons();

	turn = HERO_TURN; // Hero's play first
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	// draw graphical battlefield
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
	
	/*current_character++;
	if (current_character >= units.size()) {
		current_character = 0;
		// CHANGE TO ENEMY TURN STATE
	}*/
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	units[0]->Draw();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	// BUTTON PRESSED
	if (x <= (attack_button.GetXCoord() + attack_button.GetWidth()) && x >= attack_button.GetXCoord()) {
		if (y <= (attack_button.GetYCoord() + attack_button.GetHeight()) && y >= attack_button.GetYCoord()) {
			attack_button.resize();
			attack_button.update();
			if (selected_character != -1) { // if the user has selected a character
				// conduct battle between the current unit and the selected unit
				int attack_x = units[current_character]->getRow();
				int attack_y = units[current_character]->getCol();
				int victim_x = units[selected_character]->getRow();
				int victim_y = units[selected_character]->getCol();

				std::cout << "attack_x " << attack_x << std::endl;
				std::cout << "attack_y " << attack_y << std::endl;
				std::cout << "victim_x " << victim_x << std::endl;
				std::cout << "victim_y " << victim_y << std::endl;


				engine->ConductBattle(attack_x, attack_y, victim_x, victim_y);
				if (units[selected_character]->getHealth() <= 0) { // if victim's health is <= 0, remove character from field
					delete units[selected_character]; // remove character from graphical
					units[selected_character] = nullptr;
					engine->RemoveCharacter(victim_x, victim_y, selected_character); // removes character from battlefield array
				}
				// if ConductBattle was successful, do an animation graphically for the attack
				// if the victim happens to be killed in the battle, then remove them graphically and from the battlefield
				selected_character = -1; // reset selected_character
			}
		}
	}

	// DEFENSE BUTTON
	if (x <= (defense_button.GetXCoord() + defense_button.GetWidth()) && x >= defense_button.GetXCoord()) {
		if (y <= (defense_button.GetYCoord() + defense_button.GetHeight()) && y >= defense_button.GetYCoord()) {
			defense_button.resize();
			defense_button.update();
		}
	}

	// SPECIAL SKILL BUTTON
	if (x <= (special_skill.GetXCoord() + special_skill.GetWidth()) && x >= special_skill.GetXCoord()) {
		if (y <= (special_skill.GetYCoord() + special_skill.GetHeight()) && y >= special_skill.GetYCoord()) {
			special_skill.resize();
			special_skill.update();
		}
	}

	// SPECIAL ATTACK BUTTON
	if (x <= (special_attack.GetXCoord() + special_attack.GetWidth()) && x >= special_attack.GetXCoord()) {
		if (y <= (special_attack.GetYCoord() + special_attack.GetHeight()) && y >= special_attack.GetYCoord()) {
			special_attack.resize();
			special_attack.update();
		}
	}

	// PASS TURN BUTTON
	if (x <= (pass_turn.GetXCoord() + pass_turn.GetWidth()) && x >= pass_turn.GetXCoord()) {
		if (y <= (pass_turn.GetYCoord() + pass_turn.GetHeight()) && y >= pass_turn.GetYCoord()) {
			pass_turn.resize();
			pass_turn.update();
			if (turn == HERO_TURN) {
				turn = ENEMY_TURN;
			}
			else {
				turn = HERO_TURN;
			}
		}
	}

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

void ofApp::initButtons() {
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

void ofApp::pixelToIndex(int &pixel_X, int &pixel_Y) {
	// 200, 675 is bottom left in graphical (0, 0)
	pixel_X = (pixel_X - 200) / 25;
	pixel_Y = (675 - pixel_Y) / 25;
}
