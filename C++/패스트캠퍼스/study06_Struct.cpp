#include <iostream>
#include <string>
using namespace std;
/* ����ü�� Ŭ������ ������
   
   �Ϲ������� C++ Ŭ������ ����ü���� �� ȿ������ �����̴�.
   ����ü�� Ŭ������ ���� ����ϰ� ����������, Ŭ���������� ���������� '�Լ�'���� ������ �� �ִ�.
   
   ���� Ŭ������ ���(Inheritance)���� ������ ���α׷��ֿ��� �״�� �̿��� �� �ִٴ� ������
   ��ü ���� ���α׷���(Object-Oriented Programming)�� �����ϵ��� ���ִ� �⺻���� �����̴�. */

// ����ü����
struct student
{
	string name;
	int score;
};

int main()
{
	struct student a;
	a.name = "dohyun";
	a.score = 100;
	cout << a.name << " : " << a.score << "��\n";
	return 0;
}