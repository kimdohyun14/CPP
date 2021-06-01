//가상 함수와 동적 바인딩
//정적 바인딩은 타입을 따라 간다. (cpp은 기본 바인딩이 정적 바인딩)
#include <iostream>
using namespace std;

class Weapon {
public:
	Weapon(int power) : power(power) {
		cout << "Weapone(int)" << endl;
	}

	/*
	* 가상 함수는 프로그램을 만드는 시점(컴파일 시간)에는 알 수 없으니까
	* 프로그램이 실행되는 시점(런타임) 시점에서 결정하게끔 한다.
	*/
	virtual void Use() { //가상 함수
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

	Weapon* currentWeapon;    //내 손에 지금 어떤 무기를 들고 있는지
	currentWeapon = &mySword; //검을 착용해보자.
	currentWeapon->Use();     //기본적으로 정적 바인딩이 실행됨, 검에 따른 공격을 출력하고 싶을 때 동적 바인딩을 이용하자. (virtual 키워드)
	currentWeapon = &myMagic;
	currentWeapon->Use();     //동적 바인딩
	return 0;
}
