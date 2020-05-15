#include <iostream>
using namespace std;

// 상속

/* 상속(Inheritance)는 객체 지향 프로그래밍의 주요한 특성 중 하나이다.
   현실 세계에서의 상속의 개념을 프로그래밍으로 그대로 가져와 사용할 수 있다.
   이를 통해 프로그램의 논리적 구조를 계층적으로 구성할 수 있다.
   
   흔히 자식이 부모의 속성을 물려 받듯이, 자식 클래스(Child Class)가 부모 클래스(Parent Class)의 속성을 그대로
   물려 받아 사용할 수 있다. 그러므로 상속을 활용하여 소스코드의 재사용성을 높일 수 있게 된다. 
   
   부모 클래스
	   |      
   자식 클래스
   
   자식 클래스는 파상 클래스(Derived Class)라고도 불리우며, 부모 클래스의 모든 속성을 물려 받는다.
   또한 콜론을 활용하여 부모 클래스와 연결될 수 있다. */

// 상속에서의 생성자와 소멸자

/* 자식 클래스의 인스턴스를 만들 때, 가장 먼저 부모 클래스의 생성자가 호출된다. 이후에 자식 클래스의 생성자가 호출된다.
   또한 자식 클래스의 수명이 다했을 때는 자식 클래스의 소멸자가 먼저 호출된 이후에 부모 클래스의 소멸자가 호출된다.
   
   정리하면, 자식 인스턴스 생성 : 부모 클래스 생성자 -> 자식 클래스 생성자
             자식 인스턴스 소멸 : 자식 클래스 소멸자 -> 부모 클래스 소멸자 
*/

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
};

int main()
{
	Student student(1, "dohyun");
	student.show();
	return 0;
}