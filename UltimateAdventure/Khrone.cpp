#include "Khrone.h"

Khrone::Khrone() {}

Khrone::Khrone(int x, int y, char t, int a, int d, int h, int s, int range) {
	x_coord = x;
	y_coord = y;
	type = t;
	attack_power = a;
	defense_power = d;
	health = h;
	steps_per_turn = s;
	attack_range = range;
	attack.load("swordattack.flac");
}

int Khrone::Attack() {
	if (made_action) { // if character has already made a move this turn
		return -1;
	} else {
		made_action = true;
		attack.play();
	}
	return attack_power;
}

void Khrone::Defend() {
	if (made_action) { // if character has already made a move this turn
		return;
	} else {
		made_action = true;
	}
	defense_power += 10;
}

int Khrone::StrongAttack() {
	if (made_action) { // if character has already made a move this turn
		return -1;
	}
	if (special_attack_active) {
		made_action = true;
		special_attack_active = false;
		int strong_attack = attack_power + 10;
		attack.play();
		return strong_attack;
	} else {
		return -1;
	}
}

void Khrone::SpecialSkill() {
	if (special_skill_active) {
		attack_power += 5;
		steps_per_turn += 3;
		special_skill_active = false;
	}
}

void Khrone::setup() {
	image.load("Khrone.png");
	image.resize(50, 50);
}

void Khrone::draw() {
	image.draw(x_coord, y_coord);
}

void Khrone::Draw() {
	draw();
}

void Khrone::SetUp() {
	setup();
}

std::string Khrone::GetName() {
	return "Khrone";
}

void Khrone::ResetCharacter() {
	// resets steps and any buffs from previous turn
	steps_per_turn = 3;
	attack_power = 15;
	defense_power = 0;
	made_action = false;
}

void Khrone::DisplayInformation(int x, int y) {
	int X = x;
	int Y = y;
	std::string name = GetName();
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	std::string display_health = "Health: " + to_string(health);
	std::string attack = "Attack: " + to_string(attack_power);
	std::string defense = "Defense: " + to_string(defense_power);
	std::string steps_left = "Steps Left: " + to_string(steps_per_turn);
	std::string range = "Range: " + to_string(attack_range);
	std::string special_skill = "Special Skill: (A)";
	if (!special_skill_active) {
		special_skill = "Special Skill: (U)";
	}
	special_skill = special_skill + "\nAttack +5. \nSteps + 3";
	std::string strong_attack = "Strong Attack: (A)";
	if (!special_attack_active) {
		strong_attack = "Strong Attack: (U)";
	}
	strong_attack = strong_attack + "\nAttack + 10 damage";

	std::vector<std::string> stats;
	stats.push_back(display_health);
	stats.push_back(attack);
	stats.push_back(defense);
	stats.push_back(steps_left);
	stats.push_back(range);
	stats.push_back(special_skill);
	stats.push_back(strong_attack);

	ofDrawBitmapString("     " + name, x, y);
	y += 15;
	for (std::string stat : stats) {
		ofDrawBitmapString(stat, x, y);
		y += 15;
		if (stat.compare(special_skill) == 0 || stat.compare(strong_attack) == 0) {
			y += 30;
		}
	}
}