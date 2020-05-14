#include <iostream>
#include <string>
using namespace std;

/* 객체 지향 프로그래밍의 특징 
   
   C++은 클래스를 이용해 현실 세계의 사물인 객체를 프로그램 내에서 구현할 수 있도록 해주며,
   객체 지향 프로그래밍은 다음과 같은 특징 때문에 소스코드를 보다 간결하고 생산성 높게 만들어 준다.
   
   1) 추상화 (Abstract)
   2) 캡슐화 (Encapsulation)
   3) 상속화 (Inheritance)
   4) 정보 은닉(Data Hiding)
   5) 다형성 (Polymorphism)
*/

// C++의 클래스 : 멤버(Member)
/* 멤버 변수를 속성, 혹은 프로퍼티(Property)
   멤버 함수를 메소드(Method)라고도 부른다. */

// C++의 클래스 : 접근 한정자
/* public: 클래스, 멤버 등을 외부로 공개한다. 해당 객체를 사용하는 어떤 곳에서도 접근할 수 있다. 
   private: 클래스, 멤버 등을 내부에서만 활용한다. 외부에서 해당 객체에 접근할 수 없다. 
   
   클래스는 기본적으로 멤버를 private 형태로 간주한다. 반대로 구조체는 기본적으로 멤버를 public으로 간주한다.
   따라서 클래서에서 private 부분을 제외하면 멤버는 자동적으로 private문법을 따른다.
   
   구조체와 클래스의 차이점이기도하다.*/

class Student
{
private: // default가 private
	string name;
	int score;
public:
	Student(string n, int s) { name = n; score = s; }
	void show() { cout << name << " : " << score << "점\n"; }
};

// C++의 클래스 : 인스턴스(Instance)
/* C++에서는 클래스를 활용해 만든 변수를 인스턴스(Instance)라고 한다.
   실제로 프로그램 상에서 객체가 살아서 동작하도록 해준다.
   하나의 클래스에서 여러 개의 서로 다른 인스턴스를 만들 수 있다. */

int main()
{
	Student a = Student("dohyun", 100);
	a.show();
	return 0;
}