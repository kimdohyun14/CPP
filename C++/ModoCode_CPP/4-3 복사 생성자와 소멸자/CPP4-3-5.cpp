// ����Ʈ ���� �������� �Ѱ�
#include <cstring>
#include <iostream>

// C++���� ���ڿ��� �ٷꋚ C��� ó�� �� ���� char �迭�� �ٷ�� ���� ����
// C++ ǥ�� ���̺귯������ std::string�̶�� �Ǹ��� ���ڿ� Ŭ������ �����Ѵ�.

class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(int x, int y, const char* cannon_name);
	Photon_Cannon(const Photon_Cannon& pc); //���� ���� �߰� 
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
	std::cout << "���� ������ ȣ��!" << std::endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	//���� ���� �����߰�
	//���� �����ڿ��� name�� �״�� �������� ����
	//���� �ٸ� �޸𸮿� ���� �Ҵ��� �ؼ� �� ���븸 �����Ѵ�.
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
	// 0 �� �ƴ� ���� if ������ true �� ó���ǹǷ�
	// 0 �ΰ� �ƴѰ��� ���� �� �׳� if(name) �ϸ�
	// if(name != 0) �� ������ �ǹ̸� ���� �� �ִ�.

	// ����� if �� ������ ������ 1 ���� �´ٸ�
	// �߰�ȣ�� ���� �����ϴ�.

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
	Photon_Cannon pc2 = pc1; //����Ʈ ���� ������ ȣ��

	pc1.show_status();
	pc2.show_status();
	return 0;
}

//������ : �ѹ� ������ �޸𸮴� �ٽ� ������ �� ����. ���� ����(shallow copy)
//���� ���� pc1�� �Ҹ��ڿ� ���ؼ� �ı��Ǿ��ٰ��ϸ�,
//pc1�� ������ ��� �ı��԰� ���ÿ� name�� �Ҵ��� �޸𸮱��� delete�ϰ� �ȴ�.
//������ pc2�� name�� �̹� ������ �޸𸮸� ����Ű�� �ִٴ� ���̴�.
//�̹� ������ �޸𸮿� �����ؼ� �ٽ� �����Ϸ��� �Ͽ��� ������ ��Ÿ�� �����߻�

//�ذ��� : ���� ����(deep copy)�� �����.