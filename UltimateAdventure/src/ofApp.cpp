#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	std::vector<Character*> character_vector; // all characters in game
	// create character and add it to the vector
	Alexander *obj = new Alexander;
	Character* character = obj;
	character->setCol(10);
	character->setRow(10);
	character_vector.push_back(character);
	GameEngine gameengine(character_vector);
	engine = gameengine;


	ofSetWindowTitle("Ultimate Adventure");
	background.load("prolouge.mp3");
	background.play();
	background.setLoop(true);
	alexander.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255); // white color
	ofDrawRectangle(150, 50, 650, 650);
	/*ofSetColor(255, 0, 0);
	ofDrawRectangle(ofGetMouseX() - 25, ofGetMouseY() - 25, 50, 50);*/
	alexander.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int upper_key = toupper(key);

	// move character on graphical display and array
	if (upper_key == 'W') {
		alexander.SetDirection(UP);
		engine.MoveCharacter(UP, 0);
		alexander.draw();
	} else if (upper_key == 'A') {
		alexander.SetDirection(LEFT);
		engine.MoveCharacter(LEFT, 0);
		alexander.draw();
	} else if (upper_key == 'S') {
		alexander.SetDirection(DOWN);
		engine.MoveCharacter(DOWN, 0);
		alexander.draw();
	} else if (upper_key == 'D') {
		alexander.SetDirection(RIGHT);
		engine.MoveCharacter(RIGHT, 0);
		alexander.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofSetColor(255, 255, 0);
	ofDrawRectangle(x, y, 300, 300);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
