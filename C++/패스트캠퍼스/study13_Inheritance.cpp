#include <iostream>
using namespace std;

// ���

/* ���(Inheritance)�� ��ü ���� ���α׷����� �ֿ��� Ư�� �� �ϳ��̴�.
   ���� ���迡���� ����� ������ ���α׷������� �״�� ������ ����� �� �ִ�.
   �̸� ���� ���α׷��� ���� ������ ���������� ������ �� �ִ�.
   
   ���� �ڽ��� �θ��� �Ӽ��� ���� �޵���, �ڽ� Ŭ����(Child Class)�� �θ� Ŭ����(Parent Class)�� �Ӽ��� �״��
   ���� �޾� ����� �� �ִ�. �׷��Ƿ� ����� Ȱ���Ͽ� �ҽ��ڵ��� ���뼺�� ���� �� �ְ� �ȴ�. 
   
   �θ� Ŭ����
	   |      
   �ڽ� Ŭ����
   
   �ڽ� Ŭ������ �Ļ� Ŭ����(Derived Class)��� �Ҹ����, �θ� Ŭ������ ��� �Ӽ��� ���� �޴´�.
   ���� �ݷ��� Ȱ���Ͽ� �θ� Ŭ������ ����� �� �ִ�. */

// ��ӿ����� �����ڿ� �Ҹ���

/* �ڽ� Ŭ������ �ν��Ͻ��� ���� ��, ���� ���� �θ� Ŭ������ �����ڰ� ȣ��ȴ�. ���Ŀ� �ڽ� Ŭ������ �����ڰ� ȣ��ȴ�.
   ���� �ڽ� Ŭ������ ������ ������ ���� �ڽ� Ŭ������ �Ҹ��ڰ� ���� ȣ��� ���Ŀ� �θ� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�.
   
   �����ϸ�, �ڽ� �ν��Ͻ� ���� : �θ� Ŭ���� ������ -> �ڽ� Ŭ���� ������
             �ڽ� �ν��Ͻ� �Ҹ� : �ڽ� Ŭ���� �Ҹ��� -> �θ� Ŭ���� �Ҹ��� 
*/

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
};

int main()
{
	Student student(1, "dohyun");
	student.show();
	return 0;
}