#include <iostream>
using namespace std;

// C++�� ĸ��ȭ ���

/* �⺻������ ��� ������ �����ϱ� ���ؼ� public ��� �Լ��� �̿��ؾ� �Ѵ�. �ٸ� Ư���� ��ü�� ��� �Լ��� �ƴ� ��쿡��
   private ����� �����ؾ� �� ���� �ִ�. �� �� friend Ű���带 ����ϸ� Ư���� ��ü�� ��� ����� ������ �����ϴ�. 
   
   ĸ��ȭ(Encapsulation)�� ��ü ���� ���α׷��� ������� �߿��� Ű�����̴�. ĸ��ȭ�� �⺻ ������ ���õ� �Լ��� �������
   �ϳ��� Ŭ�������� �����ϴ� ���̴�. ���� ���� ����Ǿ�� �ϴ� ��ɵ鵵 �ϳ��� Ŭ������ �־ �� ��ü�� ������ �����
   ���� �� �ֵ��� �ϴ� ���̴�.*/

// friend Ű���� ����غ���.

class Student
{
private:
    int studentId;
    string name;
public:
    Student(int studentId, string name) : studentId(studentId), name(name) {}
    // ���� �Ű������� �ڱ� �ڽ�, ������ �Ű������� ������ �ǹ�
    // �Ű������� 2�� ����ϴ� �������� �����ε� ��쿡�� �տ� friend Ű���带 ������.
    friend Student operator +(const Student& student, const Student& other)
    {
        // friend Ű���带 �̿��� �̸��� ������ �����ϴ�.
        return Student(student.studentId, student.name + " & " + other.name);
    }
    void showName() { cout << "�̸�: " << name << '\n'; }
};

int main()
{
    Student student(1, "dohyun");
    Student result = student + student;
    result.showName();
	return 0;
}