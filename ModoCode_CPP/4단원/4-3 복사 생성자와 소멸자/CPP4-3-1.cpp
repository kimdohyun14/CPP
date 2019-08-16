//복사 생성자, 소멸자에 대해서 알아보자.
//복사 생성자 (깊은 복사, 얕은 복사)
//소멸자(destructor)

#include <iostream>

class Marine {
	int hp;                 // 마린 체력
	int coord_x, coord_y;   // 마린 위치
	int damage;             // 마린 공격력
	bool is_dead;           // 생사여부

public:
	Marine();               // 기본 생성자
	Marine(int x, int y);   // x, y좌표에 마린 생성

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
}

Marine::Marine(int x, int y) {
	coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
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
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	return 0;
}