#include <iostream>
using namespace std;

// C++ 정적 멤버

/* 정적 멤버(Static Member)란 클래스에는 포함 되어 있는 멤버이지만 모든 객체가 공유하는 멤버이다.
   정적으로 선언된 멤버는 메모리 상에 오직 하나만 할당되어 관리된다.
   
   정적 멤버를 public으로 선언하면 외부의 어떠한 클래스에서 접근이 가능하며, 오직 하나만 관리된다.
   정적 멤버는 일반적으로 싱글톤 패턴(Singleton Pattern) 등의 다양한 기능을 위해 사용된다. */

class Person
{
private:
    string name;
public:
    static int count;
    Person(string name) : name(name)
    {
        count++;
    }
};

int Person::count = 0; // Person이라는 클래스 전체가 공유하는 count 정적 변수의 값을 0으로 초기화

int main()
{
    Person p1("AAA");
    Person p2("BBB");
    Person p3("CCC");
    cout << "사람의 수 : " << Person::count << '\n';
    return 0;
}