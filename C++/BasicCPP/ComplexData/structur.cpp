#include <iostream>
using namespace std;

// ����ü : ��� ������ �ϳ��� ������ ���� �� �ִ� ������ ����
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	// C ��Ÿ�Ͽ����� struct�� �䱸������, C++ ��Ÿ�Ͽ����� �䱸���� �ʴ´�.
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99
	};

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "���� �Ǹ��ϰ� �ִ� ����ǳ����\n" << guest.name << "�� "
		<< pal.name << "�Դϴ�.\n";
	cout << "�� ��ǰ�� $" << guest.price + pal.price << "�� �帮�ڽ��ϴ�!\n";
	return 0;
}