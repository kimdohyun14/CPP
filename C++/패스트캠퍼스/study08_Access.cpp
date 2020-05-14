#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int englishScore;
	int mathScore;
	int getSum() { return englishScore + mathScore; } // 정보 은닉 (Data Hiding)
public:
	Student(string n, int e, int m)
	{
		name = n;
		englishScore = e;
		mathScore = m;
	}
	void show() { cout << name << " : [합계 " << getSum() << "점]\n"; }
};


int main()
{
	Student a = Student("dohyun", 100, 99);
	a.show(); // 클래스 내부에서 정의된 멤버 함수를 불러올 때는 멤버 참조 연산자(.)를 사용해서 불러온다.
	// cout << a.getSum(); private 접근 한정자는 외부에서 접근할 수 없다. (error)
	return 0;
}