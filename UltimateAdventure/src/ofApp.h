#pragma once
#include "ofMain.h"
#include "GameEngine.h"
#include "Character.h"
#include "Alexander.h"
#include "Direction.h"
#include "Button.h"

class ofApp : public ofBaseApp{
	private:
		GameEngine *engine;
		std::vector<Character*> units;
		std::vector<Button> buttons;
		int current_character;
		Character* s_character;
		int selected_character = -1;

		// all buttons in game
		Button attack_button;
		Button defense_button;
		Button special_skill;
		Button special_attack;
		
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// My Helper Methods
		void initButtons();
		void pixelToIndex(int &pixel_X, int &pixel_Y);

		ofSoundPlayer background;
		
};
