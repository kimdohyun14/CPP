#include <iostream>
using namespace std;

// C++의 캡슐화 기법

/* 기본적으로 멤버 변수에 접근하기 위해서 public 멤버 함수를 이용해야 한다. 다만 특정한 객체의 멤버 함수가 아닌 경우에도
   private 멤버에 접근해야 할 때가 있다. 이 때 friend 키워드를 사용하면 특정한 객체의 모든 멤버에 접근이 가능하다. 
   
   캡슐화(Encapsulation)란 객체 지향 프로그래밍 기법에서 중요한 키워드이다. 캡슐화의 기본 원리는 관련된 함수는 멤버들을
   하나의 클래스에서 관리하는 것이다. 또한 같이 실행되어야 하는 기능들도 하나의 클래스에 넣어서 각 객체가 응집된 기능을
   가질 수 있도록 하는 것이다.*/

// friend 키워드 사용해보기.

class Student
{
private:
    int studentId;
    string name;
public:
    Student(int studentId, string name) : studentId(studentId), name(name) {}
    // 왼쪽 매개변수는 자기 자신, 오른쪽 매개변수는 상대방을 의미
    // 매개변수를 2개 사용하는 연산자의 오버로딩 경우에는 앞에 friend 키워드를 붙이자.
    friend Student operator +(const Student& student, const Student& other)
    {
        // friend 키워드를 이용해 이름에 접근이 가능하다.
        return Student(student.studentId, student.name + " & " + other.name);
    }
    void showName() { cout << "이름: " << name << '\n'; }
};

int main()
{
    Student student(1, "dohyun");
    Student result = student + student;
    result.showName();
	return 0;
}