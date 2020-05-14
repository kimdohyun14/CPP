#include <iostream>
#include <string>
using namespace std;
/* 구조체와 클래스의 차이점
   
   일반적으로 C++ 클래스는 구조체보다 더 효과적인 문법이다.
   구조체와 클래스는 거의 흡사하게 동작하지만, 클래스에서는 내부적으로 '함수'등을 포함할 수 있다.
   
   또한 클래스는 상속(Inheritance)등의 개념을 프로그래밍에서 그대로 이용할 수 있다는 점에서
   객체 지향 프로그래밍(Object-Oriented Programming)을 가능하도록 해주는 기본적인 단위이다. */

// 구조체부터
struct student
{
	string name;
	int score;
};

int main()
{
	struct student a;
	a.name = "dohyun";
	a.score = 100;
	cout << a.name << " : " << a.score << "점\n";
	return 0;
}