#include <iostream>
using namespace std;

// C++�� �Լ� �����ε�

// C++�� ������ �̸��� ��� �Լ��� �پ��� ������� Ȱ���ϱ� ���ؼ� �����ε��� ����� �� �ִ�.

class Person
{
private:
	string name;
public:
	Person() { name = "dohyun"; }
	Person(string name) : name(name) { }
	void showName() { cout << "�̸�: " << name << '\n'; }
};

int main()
{
	Person person1;
	person1.showName();
	Person person2("greedy");
	person2.showName();
	return 0;
}