#pragma once
#include "ofMain.h"
#include <string>
class Button {
private:
	int x_coord;
	int y_coord;
	int width;
	int height;
	std::string f_name;

public:
	Button(); // default constructor
	Button(int x, int y, int w, int h);
	int GetWidth();
	int GetHeight();
	int GetXCoord();
	int GetYCoord();
	void setup(std::string f_name);
	void draw();
	void update();
	void resize();
	void SetXYCoord(int x, int y);
	bool IsClicked(int x, int y); // pass in x & y mouse position
	ofImage button;
	ofImage prev_image;
};