//���� �Լ��� ���� ���ε�
//���� ���ε��� Ÿ���� ���� ����. (cpp�� �⺻ ���ε��� ���� ���ε�)
#include <iostream>
using namespace std;

class Weapon {
public:
	Weapon(int power) : power(power) {
		cout << "Weapone(int)" << endl;
	}

	/*
	* ���� �Լ��� ���α׷��� ����� ����(������ �ð�)���� �� �� �����ϱ�
	* ���α׷��� ����Ǵ� ����(��Ÿ��) �������� �����ϰԲ� �Ѵ�.
	*/
	virtual void Use() { //���� �Լ�
		cout << "Weapon::Use()" << endl;
	}

protected:
	int power;
};

class Sword : public Weapon {
public:
	Sword(int power) : Weapon(power) {
		cout << "Sword(int)" << endl;
	}

	void Use() {
		cout << "Sword::Use()" << endl;
		Swing();
	}

private:
	void Swing() {
		cout << "Swing sword" << endl;
	}
};

class Magic : public Weapon {
public:
	Magic(int power, int mana) : Weapon(power), manaCost(mana) {
		cout << "Magic(int, int)" << endl;
	}

	void Use() {
		cout << "Magic::Use()" << endl;
		Cast();
	}

private:
	int manaCost;
	void Cast() {
		cout << "Cast magic" << endl;
	}
};

int main() {
	Sword mySword(10);
	Magic myMagic(15, 7);

	mySword.Use();
	myMagic.Use();

	Weapon* currentWeapon;    //�� �տ� ���� � ���⸦ ��� �ִ���
	currentWeapon = &mySword; //���� �����غ���.
	currentWeapon->Use();     //�⺻������ ���� ���ε��� �����, �˿� ���� ������ ����ϰ� ���� �� ���� ���ε��� �̿�����. (virtual Ű����)
	currentWeapon = &myMagic;
	currentWeapon->Use();     //���� ���ε�
	return 0;
}
