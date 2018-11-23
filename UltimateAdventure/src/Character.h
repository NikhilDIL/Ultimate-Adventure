#pragma once
class Character {
private:
	int row;
	int col;
public:
	Character();
	// All common among all unit classes
	virtual void Attack() = 0;
	virtual void Defend() = 0;
	virtual void StrongAttack() = 0;

	// These vary depending on the character
	virtual void FirstSpecialSkill() = 0;
	virtual void SecondSpecialSkill() = 0;

	void setRow(int r);
	void setCol(int c);

	int getRow();
	int getCol();
};
