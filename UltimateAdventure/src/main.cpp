#include <iostream>
#include <vector>
#include "ofMain.h"
#include "ofApp.h"
#include "Character.h"
#include "Alexander.h"

using std::cout;
using std::endl;

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768, OF_WINDOW);			// <-------- setup the GL context
	ofSetFrameRate(30);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
