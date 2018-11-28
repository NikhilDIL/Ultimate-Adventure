#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	current_character = 0;
	// create character and add it to the vector
	Alexander *obj = new Alexander;
	Character* character = obj;
	character->setCol(0);
	character->setRow(24);
	units.push_back(character);

	Alexander *obj2 = new Alexander(325, 675);
	Character* character2 = obj2;
	character2->setCol(5);
	character2->setRow(24);
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
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	// draw battlefield
	ofSetColor(255, 255, 255); // white color
	ofDrawRectangle(200, 75, 650, 650);

	// draw units
	units[0]->Draw();
	units[1]->Draw();

	// draw buttons
	attack_button.draw();
	defense_button.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	int upper_key = toupper(key);

	// First check if that move can be made. If it can be made then move. Else, don't move.
	// move character on graphical display and array
	if (upper_key == 'W') {
		if (engine->IsValidMove(UP, current_character)) {
			units[current_character]->SetDirection(UP);
			engine->MoveCharacter(UP, current_character);
			units[current_character]->Draw();
		}
	}
	else if (upper_key == 'A') {
		if (engine->IsValidMove(LEFT, current_character)) {
			units[current_character]->SetDirection(LEFT);
			engine->MoveCharacter(LEFT, current_character);
			units[current_character]->Draw();
		}
	}
	else if (upper_key == 'S') {
		if (engine->IsValidMove(DOWN, current_character)) {
			units[current_character]->SetDirection(DOWN);
			engine->MoveCharacter(DOWN, current_character);
			units[current_character]->Draw();
		}
	}
	else if (upper_key == 'D') {
		if (engine->IsValidMove(RIGHT, current_character)) {
			units[current_character]->SetDirection(RIGHT);
			engine->MoveCharacter(RIGHT, current_character);
			units[current_character]->Draw();
		}
	}
	current_character++;
	if (current_character >= units.size()) {
		current_character = 0;
		// CHANGE TO ENEMY TURN STATE
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
	// BUTTON PRESSED
	if (x <= (attack_button.GetXCoord() + attack_button.GetWidth()) && x >= attack_button.GetXCoord()) {
		if (y <= (attack_button.GetYCoord() + attack_button.GetHeight()) && y >= attack_button.GetYCoord()) {
			std::cout << "IT WORKS!" << std::endl;
		}
	}

	if (x <= (defense_button.GetXCoord() + defense_button.GetWidth()) && x >= defense_button.GetXCoord()) {
		if (y <= (defense_button.GetYCoord() + defense_button.GetHeight()) && y >= defense_button.GetYCoord()) {
			std::cout << "IT WORKS 2!" << std::endl;
		}
	}

	// CHARACTER PRESSED
	for (Character* hero : units) { // iterate through each character
		if (x <= (hero->getGraphicalX() + 50) && x >= hero->getGraphicalX()) {
			if (y <= (hero->getGraphicalY() + 50) && y >= hero->getGraphicalY()) {
				std::cout << "SELECTED A CHARACTER!" << std::endl;
				int x = hero->getGraphicalX();
				int y = hero->getGraphicalY();
				pixelToIndex(x, y);
				std::cout << "(" << x << "," << y << ")" << std::endl;

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
	attack_button = Button(875, 600, 50, 50);
	attack_button.setup("AttackButton");
	defense_button = Button(950, 600, 50, 50);
	defense_button.setup("DefenseButton");
}

void ofApp::pixelToIndex(int &pixel_X, int &pixel_Y) {
	// 200, 675 is bottom left in graphical (0, 0)
	pixel_X = (pixel_X - 200) / 25;
	pixel_Y = (675 - pixel_Y) / 25;
}
