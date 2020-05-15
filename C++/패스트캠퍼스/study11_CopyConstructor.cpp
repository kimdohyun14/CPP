#include <iostream>
using namespace std;

// C++ 복사 생성자

/* 복사 생성자(Copy Constructor)는 다른 인스턴스의 참조(Reference)를 인수로 받아서, 그 참조를 이용해
   자신의 인스턴스를 초기화할 수 있도록 해준다.
   
   대표적인 복사 방법인 깊은 복사(Deep Copy)를 이용해 만들어진 인스턴스는 기존의 인스턴스의 다른 메모리
   공간에 할당되어 독립적이다. */

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;
public:
	Character(string name, int hp, int damage) : name(name), ragePoint(0), hp(hp), damage(damage) { } // 멤버 이니셜라이저 방식
	Character(const Character& other) // 복사 생성자
	{
		name = other.name;
		ragePoint = other.ragePoint;
		hp = other.hp;
		damage = other.damage;
	}
	void pointUp() { ragePoint++; }
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
	}
};

int main()
{
	Character character1("슬라임", 10, 20);
	character1.pointUp();
	Character character2(character1);
	character2.pointUp();
	character1.show();
	character2.show();
	return 0;
}