#include <iostream>
using namespace std;

// C++ 생성자

/* C++에서는 생성자를 이용해 객체를 생성함과 동시에 멤버 변수를 초기화할 수 있다.
   생성자는 특별한 메소드로, 클래스의 이름과 동일한 이름의 메소드로 구현된다. 
   
   생성자는 반환 값이 없다. 여러 번 정의되어 다양한 방법으로 객체를 초기화가 가능하다. */

// C++ 기본 생성자

/* C++에서 별도로 생성자를 구현하지 않으면 기본 생성자(Default Constructor)가 사용된다.
   기본 생성자는 매개변수를 가지지 않으며 멤버 변수는 0, NULL 등의 값으로 초기화된다. */

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;
public:
	// 생성자(Constructor)
	Character(string name, int hp, int damage)
	{
		this->name = name;
		this->ragePoint = 0;
		this->hp = hp;
		this->damage = damage;
	}
	void show()
	{
		cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
	}
};

int main()
{
	Character character = Character("슬라임", 50, 10);
	character.show();
	return 0;
}