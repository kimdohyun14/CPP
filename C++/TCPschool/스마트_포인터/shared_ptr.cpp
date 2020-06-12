#include <iostream>
#include <memory>
using namespace std;

/* shared ptr
   하나의 특정 객체를 참조하는 스마트 포인터가 총 몇 개인지를 참조하는 스마트 포인터이다.
   이렇게 참조하고 있는 스마트 포인터의 개수를 참조 횟수(Reference count)라고 한다.
   참조 횟수는 특정 객체에 새로운 shared_ptr이 추가될 때마다 1씩 증가하며, 수명이 다할 때마다 1씩 감소한다.
   따라서 마지막 shared_ptr이 수명을 다하여, 참조 횟수가 0이 되면 delete 키워드를 사용하여 메모리를 자동으로 해제한다.
*/

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

int main()
{
    shared_ptr<int> ptr01(new int(5));
    // shared_ptr 객체가 현재 가리키고 있는 리소스를 참조 중인 소유자의 수를 반환
    cout << ptr01.use_count() << endl; 

    auto ptr02(ptr01); // 복사 생성자를 이용한 초기화
    cout << ptr01.use_count() << endl;

    auto ptr03 = ptr01; // 대입을 통한 초기화
    cout << ptr01.use_count() << endl;

    shared_ptr<Person> hong = make_shared<Person>("길동", 29);
    cout << "현재 소유자 수 : " << hong.use_count() << endl;
    auto han = hong;
    cout << "현재 소유자 수 : " << hong.use_count() << endl;
    han.reset(); // shared_ptr인 han 을 해제함.
    cout << "현재 소유자 수 : " << hong.use_count() << endl;
    return 0;
}