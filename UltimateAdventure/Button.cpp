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
	f_name = file_name;
	button.load(file_name);
	prev_image.load(file_name);
	prev_image.resize(width, height);
}

void Button::draw() {
	button.draw(x_coord, y_coord);
	button.resize(width, height);
	button = prev_image;
}

void Button::resize() {
	int x = width - 10;
	int y = height - 10;
	button.resize(x, y);
}

void Button::update() {
	button.update();
}

void Button::SetXYCoord(int x, int y) {
	x_coord = x;
	y_coord = y;
}

bool Button::IsClicked(int x, int y) {
	if (x <= (x_coord + width) && x >= x_coord) {
		if (y <= (y_coord + height) && y >= y_coord) {
			return true;
		}
	}
	return false;
}