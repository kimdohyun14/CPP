#include <iostream>
using namespace std;

// �������̵�

/* �������̵�(Overriding)�� �θ� Ŭ�������� ���ǵ� �Լ��� �����ϰ�, �ڽ� Ŭ�������� ������ �̸��� �Լ��� �������ϴ� ����
   �������̵��� ������ �Լ��� ������ ������ �Լ��� ������ �Ű������� ���� �޴´�. */

// ��� : �θ� Ŭ���� �����ϱ�
class Person
{
private:
	string name;
public:
	Person(string name) : name(name) { }
	string getName() { return name; }
	void showName() { cout << "�̸�: " << getName() << '\n'; }
};

// ��� : �ڽ� Ŭ���� �����ϱ�
class Student : Person
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
	return 0;
}