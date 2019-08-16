// 디폴트 복사 생성자의 한계
#include <cstring>
#include <iostream>

// C++에서 문자열을 다룰떄 C언어 처럼 널 종료 char 배열로 다루는 것을 비추
// C++ 표준 라이브러리에서 std::string이라는 훌륭한 문자열 클래스를 제공한다.

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon_Cannon& pc); //깊은 복사 추가 
	~Photon_Cannon();

	void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	std::cout << "복사 생성자 호출!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	//깊은 복사 내용추가
	//복사 생성자에서 name을 그대로 복사하지 말고
	//따로 다른 메모리에 동적 할당을 해서 그 내용만 복사한다.
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
	// 0 이 아닌 값은 if 문에서 true 로 처리되므로
	// 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
	// if(name != 0) 과 동일한 의미를 가질 수 있다.

	// 참고로 if 문 다음에 문장이 1 개만 온다면
	// 중괄호를 생략 가능하다.

	if (name) delete[] name;
}
void Photon_Cannon::show_status() {
	std::cout << "Photon Cannon :: " << name << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
}
int main() {
	Photon_Cannon pc1(3, 3, "Cannon");
	Photon_Cannon pc2 = pc1; //디폴트 복사 생성자 호출

	pc1.show_status();
	pc2.show_status();
	return 0;
}

//문제점 : 한번 해제된 메모리는 다시 해제될 수 없다. 얕은 복사(shallow copy)
//만일 먼저 pc1이 소멸자에 의해서 파괴되었다고하면,
//pc1의 내용을 모두 파괴함과 동시에 name에 할당한 메모리까지 delete하게 된다.
//문제는 pc2의 name이 이미 해제된 메모리를 가리키고 있다는 점이다.
//이미 해제된 메모리에 접근해서 다시 해제하려고 하였기 때문에 런타임 오류발생

//해결점 : 깊은 복사(deep copy)로 만든다.