#include <iostream>
using namespace std;

// 오버라이딩

/* 오버라이딩(Overriding)은 부모 클래스에서 정의된 함수를 무시하고, 자식 클래스에서 동일한 이름의 함수를 재정의하는 문법
   오버라이딩을 적용한 함수의 원형은 기존의 함수와 동일한 매개변수를 전달 받는다. */

// 상속 : 부모 클래스 정의하기
class Person
{
private:
	string name;
public:
	Person(string name) : name(name) { }
	string getName() { return name; }
	void showName() { cout << "이름: " << getName() << '\n'; }
};

// 상속 : 자식 클래스 정의하기
class Student : Person
{
private:
	int studentID;
	// 멤버 변수 name은 Person으로부터 물려 받음.
public:
	Student(int studentID, string name) : Person(name)
	{
		this->studentID = studentID;
	}
	void show()
	{
		cout << "학생 번호: " << studentID << '\n';
		cout << "학생 이름: " << getName() << "\n";
	}
	void showName() // 오버라이딩(Overriding)
	{
		cout << "학생 이름: " << getName() << '\n';
	}
};

int main()
{
	Student student(1, "dohyun");
	student.showName();
	return 0;
}