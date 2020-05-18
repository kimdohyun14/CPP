#include <iostream>
using namespace std;

// 상수 멤버

/* 상수 멤버(Constant Member)는 호출된 객체의 데이터를 변경할 수 없는 멤버를 의미한다.
   일반적으로 클래스에서 사용되는 중요한 상수는 상수 멤버 변수로 정의해서 사용하는 관행이 있다. */

class Person
{
private:
	const int id;
	string name;
public:
	static int count;
	// 처음에 생성자를 통해서 값이 할당된 이후에, 나중에 값을 바꾸려고 하면 오류가 된다.
	Person(int id, string name) : id(id), name(name) 
	{
		count++;
	}
	/*
	void setId(int id)
	{
		this->id = id; // 오류 발생 [수정 불가능]
	}
	*/
};

int Person::count = 0;

int main()
{
	Person p1(1, "AAA");
	Person p2(2, "BBB");
	Person p3(3, "CCC");
	cout << "사람의 수 : " << Person::count << '\n';
	return 0;
}