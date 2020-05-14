#include <iostream>
#include <string>
using namespace std;

// C++�� Ŭ���� : this ������

/* �⺻������ �ϳ��� Ŭ�������� ������ �ν��Ͻ�(Inheritance)�� ���� ������ �޸� ������ ��� ������ ����ǰ�,
   �����ȴ�. �ٸ� ��� �Լ��� ��� �ν��Ͻ��� �����Ѵٴ� ������, �Լ� ������ �ν��Ͻ��� ������ �ʿ䰡 �ִ�. 
   
   C++�� this �����ʹ� ������ �ڷ������� '���'��� ������ ���� ������ �� ����. */

class Student
{
private:
	string name;
	int englishScore;
	int mathScore;
	int getSum() { return englishScore + mathScore; }
public:
	Student(string name, int englishScore, int mathScore)
	{
		this->name = name; // �ڱ� �ڽ��� ��� ������ ����
		this->englishScore = englishScore;
		this->mathScore = mathScore;
	}
	void show() { cout << name << " : [�հ� : " << getSum() << "��]\n"; }
};

int main()
{
	Student a = Student("dohyun", 100, 99);
	a.show();
	return 0;
}