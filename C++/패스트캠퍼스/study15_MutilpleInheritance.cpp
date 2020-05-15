#include <iostream>
using namespace std;

// ���� ���

/* ���� ���(Multiple Inheritance)�� ���� ���� Ŭ�����κ��� ����� ��� �޴� ���� ���Ѵ� .
   
   ������ ���� ������ �ʴ´ٰ� �Ѵ�. �ٸ� C++�� �����ȴ�.
   
   ���� ����� �Ѱ�
   1. ���� ���� �θ� Ŭ������ ������ ����� ������ �� �ִ�. 
   2. �ϳ��� Ŭ������ �ǵ�ġ �ʰ� ���� �� ��ӹ��� ���ɼ��� �ִ�. */

// ���� ��� : �θ� Ŭ���� �ϳ� �� �����ϱ�
class Temp
{
public:
	void showTemp()
	{
		cout << "�ӽ� �θ� Ŭ�����Դϴ�.\n";
	}
};

class Person
{
private:
	string name;
public:
	Person(string name) : name(name) { }
	string getName() { return name; }
	void showName() { cout << "�̸�: " << getName() << '\n'; }
};

class Student : Person, public Temp // ���� ���
{
private:
	int studentID;
	// ��� ���� name�� Person���κ��� ���� ����.
public:
	Student(int studentID, string name) : Person(name)
	{
		this->studentID = studentID;
	}
	void show()
	{
		cout << "�л� ��ȣ: " << studentID << '\n';
		cout << "�л� �̸�: " << getName() << "\n";
	}
	void showName() // �������̵�(Overriding)
	{
		cout << "�л� �̸�: " << getName() << '\n';
	}
};

int main()
{
	Student student(1, "dohyun");
	student.showName();
	student.showTemp();
	return 0;
}