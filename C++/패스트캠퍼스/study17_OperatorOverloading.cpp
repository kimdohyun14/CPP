#include <iostream>
using namespace std;

// C++ 연산자 오버로딩

/* 연산자 오버로딩 문법을 활용해 연산자 또한 원하는 방식으로 수정하여 사용할 수 있다.

   1. 기존에 존재하는 연산자만 정의할 수 있다.
   2. 멤버 연산자 (.), 범위 지정 연산자 (::) 등의 몇몇 연산자는 오버로딩 처리할 수 없다.
   3. 피연산자의 개수 규칙 등 기본적인 연산자의 규칙을 따라야한다.
   4. 오버로딩이 된 연산자의 피연산자 중 하나는 사용자 정의 자료형 이어야만 한다. */

class Person
{
private:
    string name;
public:
    Person() { name = "dohyun"; }
    Person(string name) : name(name) { }
    Person operator +(const Person& other) { return Person(name + " & " + other.name); }
    void showName() { cout << "이름: " << name << '\n'; }
};

int main()
{
    Person person1;
    Person person2("doing");
    // 특정한 Person과 다른 Person을 + 한다고 한다면?
    Person result = person1 + person2;
    result.showName();
    return 0;
}