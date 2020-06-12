#include <iostream>
#include <memory>
using namespace std;

/* smart pointer
   
   C++ 프로그램에서 new 키워드를 사용해서 동적으로 할당받는 메모리는 반드시 delete로 해제해야 한다.
   프로그램의 안전성을 보장하기 위해 스마트 포인터를 제공하고 있다.
   
   스마트 포인터란 포인터처럼 동작하는 클래스 템플릿으로, 사용이 끝난 메모리를 자동으로 해제해 준다.
   
   여기서의 unique_ptr은 하나의 스마트 포인터만이 특정 객체를 소유할 수 있도록, 객체에 소유권 개념을 도입한
   스마트 포인터이다.
   
   이 스마트 포인터는 해당 객체의 소유권을 가지고 있을 때만, 소멸자가 해당 객체를 삭제할 수 있다.
   unique_ptr 인스턴스는 move() 멤버 함수를 통해 소유권을 이전할 수 있지만, 복사는 할 수 없다.
   소유권이 이전되면, 이전 unique_ptr 인스턴스는 더는 해당 객체를 소유하지 않게 재설정된다.
*/

// C++ 객체에 대해 스마트 포인터가 필요한 상황에서 주로 unique_ptr을 사용한다.

class Person
{
private:
	string name_;
	int age_;
public:
	Person(const string& name, int age);
	~Person() { cout << "소멸자 호출" << endl; }
	void ShowPersonInfo();
};

int main()
{
	unique_ptr<Person> hong = make_unique<Person>("길동", 29);
	hong->ShowPersonInfo();
	/* Person 객체를 가리키는 unique_ptr 인스턴스인 hong 은 일반 포인터와 달리
	   사용이 끝난 후에 delete 키워드를 사용하여 메모리를 해제할 필요가 없다. 
	   
	   make_unique()함수는 C++ 14부터 가능하다.*/
	return 0;
}

Person::Person(const string& name, int age)
{
	name_ = name;
	age_ = age;
	cout << "생성자 호출" << endl;
}

void Person::ShowPersonInfo()
{
	cout << name_ << "의 나이는 " << age_ << "살입니다." << endl;
}