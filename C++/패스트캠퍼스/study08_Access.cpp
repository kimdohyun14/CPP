#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int englishScore;
	int mathScore;
	int getSum() { return englishScore + mathScore; } // ���� ���� (Data Hiding)
public:
	Student(string n, int e, int m)
	{
		name = n;
		englishScore = e;
		mathScore = m;
	}
	void show() { cout << name << " : [�հ� " << getSum() << "��]\n"; }
};


int main()
{
	Student a = Student("dohyun", 100, 99);
	a.show(); // Ŭ���� ���ο��� ���ǵ� ��� �Լ��� �ҷ��� ���� ��� ���� ������(.)�� ����ؼ� �ҷ��´�.
	// cout << a.getSum(); private ���� �����ڴ� �ܺο��� ������ �� ����. (error)
	return 0;
}