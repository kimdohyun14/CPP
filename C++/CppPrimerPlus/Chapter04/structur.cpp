// structur.cpp -- ������ ����ü
#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable quest = 
	{
		"Glorious Gloria",
		1.88,
		29.99
	}; // quest�� inflatable���� ����ü �����̴�.
	   // ������ ������ �ʱ�ȭ�ȴ�.

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "���� �Ǹ��ϰ� �ִ� ����ǳ����\n" << quest.name;
	cout << "�� " << pal.name << "�Դϴ�.\n";
	cout << "�� ��ǰ�� $";
	cout << quest.price + pal.price << "�� �帮�ڽ��ϴ�!\n";
	return 0;
}