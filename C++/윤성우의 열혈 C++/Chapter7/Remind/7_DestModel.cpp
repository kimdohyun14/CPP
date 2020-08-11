#include <iostream>
#include <cstring>
using namespace std;

// 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제시키자!
class Person
{
private:
	char* name;
public:
	Person(const char* myname)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
	}
	~Person()
	{
		delete[] name;
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
};

class UnivStudent : public Person
{
private:
	char* major;
public:
	UnivStudent(const char* myname, const char* mymajor)
		:Person(myname)
	{
		int len = strlen(mymajor) + 1;
		major = new char[len];
		strcpy_s(major, len, mymajor);
	}
	~UnivStudent()
	{
		delete[] major;
	}
	void WhoAreYou() const
	{
		WhatYourName();
		cout << "My major is " << major << endl;
	}
};

int main()
{
	UnivStudent st1("Kim", "Mathmatics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}