#include <iostream>
using namespace std;

// 핵심
// Person형 포인터 변수는 Person, Student, PartTimeStudent 객체를 가리킬 수 있다.
// Student형 포인터 변수는 Student, PartTimeStudent 객체를 가리킬 수 있다.
// PartTimeStudent형 포인터 변수는 PartTimeStudent 객체를 가리킬 수 있다.

class Person
{
public:
	void Sleep()
	{
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "Study" << endl;
	}
};

class PartTimeStudent : public Student
{
public:
	void Work()
	{
		cout << "Work" << endl;
	}
};

int main()
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();
	
	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1;
	delete ptr2;
	delete ptr3;
	return 0;
}