#include <iostream>
using namespace std;

// 다중 상속

/* 다중 상속(Multiple Inheritance)는 여러 개의 클래스로부터 멤버를 상속 받는 것을 말한다 .
   
   실제로 많이 사용되지 않는다고 한다. 다만 C++은 지원된다.
   
   다중 상속의 한계
   1. 여러 개의 부모 클래스에 동일한 멤버가 존재할 수 있다. 
   2. 하나의 클래스를 의도치 않게 여러 번 상속받을 가능성이 있다. */

// 다중 상속 : 부모 클래스 하나 더 정의하기
class Temp
{
public:
	void showTemp()
	{
		cout << "임시 부모 클래스입니다.\n";
	}
};

class Person
{
private:
	string name;
public:
	Person(string name) : name(name) { }
	string getName() { return name; }
	void showName() { cout << "이름: " << getName() << '\n'; }
};

class Student : Person, public Temp // 다중 상속
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
	student.showTemp();
	return 0;
}