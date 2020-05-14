#include <iostream>
#include <string>
using namespace std;

// C++의 클래스 : this 포인터

/* 기본적으로 하나의 클래스에서 생성된 인스턴스(Inheritance)는 서로 독립된 메모리 영역에 멤버 변수가 저장되고,
   관리된다. 다만 멤버 함수는 모든 인스턴스가 공유한다는 점에서, 함수 내에서 인스턴스를 구분할 필요가 있다. 
   
   C++의 this 포인터는 포인터 자료형으로 '상수'라는 점에서 값을 변경할 수 없다. */

class Student
{
private:
	string name;
	int englishScore;
	int mathScore;
	int getSum() { return englishScore + mathScore; }
public:
	Student(string name, int englishScore, int mathScore)
	{
		this->name = name; // 자기 자신의 멤버 변수에 접근
		this->englishScore = englishScore;
		this->mathScore = mathScore;
	}
	void show() { cout << name << " : [합계 : " << getSum() << "점]\n"; }
};

int main()
{
	Student a = Student("dohyun", 100, 99);
	a.show();
	return 0;
}