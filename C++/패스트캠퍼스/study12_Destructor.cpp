#include <iostream>
using namespace std;

// C++ 소멸자

/* C++의 소멸자(Destructor)는 객체의 수명이 끝났을 때 객체를 제거하기 위한 목적으로 사용된다.
   객체의 수명이 끝났을 때 자동으로 컴파일러가 소멸자 함수를 호출한다. 
   
   C++의 소멸자 또한 생성자처럼 클래스의 이름과 동일하며 ~기호를 이용해 정의할 수 있다. */

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;
public:
	Character(string name, int hp, int damage) : name(name), ragePoint(0), hp(hp), damage(damage) { }
	~Character() // 소멸자
	{
		cout << "[객체가 소멸됩니다.]\n";
	}
	void pointUp() { ragePoint++; }
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
	}
};

int main()
{
	Character* character1 = new Character("슬라임", 10, 20);
	character1->pointUp();
	Character character2(*character1);
	character2.pointUp();
	character1->show();
	character2.show();

	delete character1;   // 동적 할당을 이용했으므로 성공적으로 소멸됨
	delete& character2;  // 동적 할당을 이용하지 않았으므로 오류가 발생함.
	return 0;
}

