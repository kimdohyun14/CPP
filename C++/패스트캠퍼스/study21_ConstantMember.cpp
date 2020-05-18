#include <iostream>
using namespace std;

// ��� ���

/* ��� ���(Constant Member)�� ȣ��� ��ü�� �����͸� ������ �� ���� ����� �ǹ��Ѵ�.
   �Ϲ������� Ŭ�������� ���Ǵ� �߿��� ����� ��� ��� ������ �����ؼ� ����ϴ� ������ �ִ�. */

class Person
{
private:
	const int id;
	string name;
public:
	static int count;
	// ó���� �����ڸ� ���ؼ� ���� �Ҵ�� ���Ŀ�, ���߿� ���� �ٲٷ��� �ϸ� ������ �ȴ�.
	Person(int id, string name) : id(id), name(name) 
	{
		count++;
	}
	/*
	void setId(int id)
	{
		this->id = id; // ���� �߻� [���� �Ұ���]
	}
	*/
};

int Person::count = 0;

int main()
{
	Person p1(1, "AAA");
	Person p2(2, "BBB");
	Person p3(3, "CCC");
	cout << "����� �� : " << Person::count << '\n';
	return 0;
}