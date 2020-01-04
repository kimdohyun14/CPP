#include <iostream>
using namespace std;

// 핵심
// 함수가 가상함수로 선언되면, 해당 함수 호출 시
// 포인터의 자료형을 기반으로 호출대상을 결정하지 않고,
// 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다.

class First
{
public:
	virtual void MyFunc()
	{
		cout << "First" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()
	{
		cout << "Second" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "Third" << endl;
	}
};

int main()
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}