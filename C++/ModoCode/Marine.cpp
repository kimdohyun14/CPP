#include <iostream>

class Marine
{
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;

public:
	Marine();
	Marine(int x, int y);

	int attack();                         // 데미지 리턴
	void be_attacked(int damage_earn);    // 입는 데미지
	void move(int x, int y);              // 새로운 위치

	void show_status();                   // 상태
};

Marine::Marine()
{
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y)
{
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}

void Marine::show_status()
{
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int main()
{
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();

	std::cout << std::endl << "마린 1 이 마린 2를 공격!" << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
	return 0;
}