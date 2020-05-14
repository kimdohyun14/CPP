//복사 생성자, 소멸자에 대해서 알아보자.
//복사 생성자 (깊은 복사, 얕은 복사)
//소멸자(destructor)

#include <iostream>
#include <cstring>

class Marine {
	int hp;                 // 마린 체력
	int coord_x, coord_y;   // 마린 위치
	int damage;             // 마린 공격력
	bool is_dead;           // 생사여부
	char* name;             // 마린 이름

public:
	Marine();									   // 기본 생성자
	Marine(int x, int y, const char* marine_name); //이름까지 지정
	Marine(int x, int y);   // x, y좌표에 마린 생성
	~Marine();              //소멸자(destructor)

	int attack();                       // 데미지를 리턴
	void be_attacked(int damage_earn);  // 입는 데미지
	void move(int x, int y);            // 새로운 위치

	void show_status();                 // 상태를 보여준다.
};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
	name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);

	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
	name = NULL;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << name << " ***" << std::endl;
	std::cout << " Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

//소멸자는 인자를 아무것도 가지지 않는다.
//소멸자는 오버로딩도 되지 않는다.
Marine::~Marine() {
	std::cout << name << "의 소멸자 호출!" << std::endl;
	//name이 동적으로 할당이 되었을 경우에만 삭제한다.
	if (name != NULL) {
		delete[] name;
	}
}

//더 많은 마린들이 싸우게 된다면 -> 배열로 정하면 된다.
//마린들에게는 고유의 이름들이 있다.
int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 1");
	marines[1] = new Marine(3, 5, "Marine 2");

	marines[0]->show_status();
	marines[1]->show_status();

	Marine marine1(2, 3);
	Marine marine2(3, 5);

	std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
	return 0;
}