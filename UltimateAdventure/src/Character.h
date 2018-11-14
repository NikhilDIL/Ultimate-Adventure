#pragma once

class Character {
public:
	// All common among all unit classes
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void StrongAttack() = 0;

	// These vary depending on the character
	virtual void FirstSpecialSkill() = 0;
	virtual void SecondSpecialSkill() = 0;
};
