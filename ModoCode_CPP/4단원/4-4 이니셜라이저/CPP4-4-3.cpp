//꼭 필요한 경우가 아니면 전역변수는 사용하지 않는다.

//전역 변수 같지만 클래스 하나에만 종속되는 변수
//바로 static 멤버 변수이다.
//어떤 클래스의 static 멤버 변수의 경우,
//멤버 변수들 처럼, 객체가 소멸될 때 소멸되는 것이 아닌,
//프로그램이 종료될 때 소멸되는 것이다.

//또한, 이 static 멤버 변수의 경우, 클래스의 모든 객체들이 '공유'하는 변수로써
//각 객체 별로 따로 존재하는 멤버 변수들과 달리 모든 객체들이 '하나의' static
//멤버 변수를 사용하게 된다.


//static 멤버 변수의 사용
#include <iostream>

class Marine {
	//모든 전역 및 static 변수들은 정의와 동시에 값이 자동으로 0으로 초기화
	//다만 클래스 static 변수들의 경우는 초기화한다.
	//클래스 내부에서 멤버 변수를 직접 초기화할 수 없다.
	//다만 const static int x = 0의 형태는 가능하다.
	static int total_marine_num;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();

	~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine()
	:hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y)
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
	: coord_x(x),
	coord_y(y),
	hp(50),
	default_damage(default_damage),
	is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << ", " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

int main() {
	Marine marine1(2, 3, 5);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	create_marine();

	std::cout << std::endl << "마린1이 마린2를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	return 0;
}