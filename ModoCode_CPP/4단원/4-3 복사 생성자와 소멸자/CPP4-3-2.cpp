//���� ������, �Ҹ��ڿ� ���ؼ� �˾ƺ���.
//���� ������ (���� ����, ���� ����)
//�Ҹ���(destructor)

#include <iostream>
#include <cstring>

class Marine {
	int hp;                 // ���� ü��
	int coord_x, coord_y;   // ���� ��ġ
	int damage;             // ���� ���ݷ�
	bool is_dead;           // ���翩��
	char* name;             // ���� �̸�

public:
	Marine();									   // �⺻ ������
	Marine(int x, int y, const char* marine_name); //�̸����� ����
	Marine(int x, int y);   // x, y��ǥ�� ���� ����
	~Marine();              //�Ҹ���(destructor)

	int attack();                       // �������� ����
	void be_attacked(int damage_earn);  // �Դ� ������
	void move(int x, int y);            // ���ο� ��ġ

	void show_status();                 // ���¸� �����ش�.
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

//�Ҹ��ڴ� ���ڸ� �ƹ��͵� ������ �ʴ´�.
//�Ҹ��ڴ� �����ε��� ���� �ʴ´�.
Marine::~Marine() {
	std::cout << name << "�� �Ҹ��� ȣ��!" << std::endl;
	//name�� �������� �Ҵ��� �Ǿ��� ��쿡�� �����Ѵ�.
	if (name != NULL) {
		delete[] name;
	}
}

//�� ���� �������� �ο�� �ȴٸ� -> �迭�� ���ϸ� �ȴ�.
//�����鿡�Դ� ������ �̸����� �ִ�.
int main() {
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 1");
	marines[1] = new Marine(3, 5, "Marine 2");

	marines[0]->show_status();
	marines[1]->show_status();

	Marine marine1(2, 3);
	Marine marine2(3, 5);

	std::cout << std::endl << "���� 1�� ���� 2�� ����! " << std::endl;

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
	return 0;
}