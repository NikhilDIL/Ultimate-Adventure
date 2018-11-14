#include <iostream>
#include <vector>
#include "ofMain.h"
#include "ofApp.h"
#include "GameEngine.h"
#include "Warrior.h"
#include "Alexander.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	std::cout << "hello world" << std::endl;

	std::vector<Character*> character_vector; // all characters in game

	// create character and add it to the vector
	Alexander alexander;
	Character* character = &alexander;
	character_vector.push_back(character);

	GameEngine gameengine(character_vector);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());



}
