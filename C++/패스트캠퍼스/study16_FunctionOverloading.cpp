#include <iostream>
using namespace std;

// C++의 함수 오버로딩

// C++은 동일한 이름의 멤버 함수를 다양한 방식으로 활용하기 위해서 오버로딩을 사용할 수 있다.

class Person
{
private:
	string name;
public:
	Person() { name = "dohyun"; }
	Person(string name) : name(name) { }
	void showName() { cout << "이름: " << name << '\n'; }
};

int main()
{
	Person person1;
	person1.showName();
	Person person2("greedy");
	person2.showName();
	return 0;
}