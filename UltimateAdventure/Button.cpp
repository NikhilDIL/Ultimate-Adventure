#include "Button.h"

Button::Button() {}

Button::Button(int x, int y, int w, int h) {
	x_coord = x;
	y_coord = y;
	width = w;
	height = h;
}

int Button::GetXCoord() {
	return x_coord;
}

int Button::GetYCoord() {
	return y_coord;
}

int Button::GetWidth() {
	return width;
}

int Button::GetHeight() {
	return height;
}

void Button::setup(std::string f_name) {
	std::string file_name = f_name + ".png";
	button.load(file_name);
}

void Button::draw() {
	button.draw(x_coord, y_coord);
	button.resize(width, height);
}

void Button::SetXYCoord(int x, int y) {
	x_coord = x;
	y_coord = y;
}