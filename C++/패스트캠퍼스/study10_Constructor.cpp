#include <iostream>
using namespace std;

// C++ ������

/* C++������ �����ڸ� �̿��� ��ü�� �����԰� ���ÿ� ��� ������ �ʱ�ȭ�� �� �ִ�.
   �����ڴ� Ư���� �޼ҵ��, Ŭ������ �̸��� ������ �̸��� �޼ҵ�� �����ȴ�. 
   
   �����ڴ� ��ȯ ���� ����. ���� �� ���ǵǾ� �پ��� ������� ��ü�� �ʱ�ȭ�� �����ϴ�. */

// C++ �⺻ ������

/* C++���� ������ �����ڸ� �������� ������ �⺻ ������(Default Constructor)�� ���ȴ�.
   �⺻ �����ڴ� �Ű������� ������ ������ ��� ������ 0, NULL ���� ������ �ʱ�ȭ�ȴ�. */

class Character
{
private:
	string name;
	int ragePoint;
	int hp;
	int damage;
public:
	// ������(Constructor)
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
	Character character = Character("������", 50, 10);
	character.show();
	return 0;
}