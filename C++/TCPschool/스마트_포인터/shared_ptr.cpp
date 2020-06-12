#include <iostream>
#include <memory>
using namespace std;

/* shared ptr
   �ϳ��� Ư�� ��ü�� �����ϴ� ����Ʈ �����Ͱ� �� �� �������� �����ϴ� ����Ʈ �������̴�.
   �̷��� �����ϰ� �ִ� ����Ʈ �������� ������ ���� Ƚ��(Reference count)��� �Ѵ�.
   ���� Ƚ���� Ư�� ��ü�� ���ο� shared_ptr�� �߰��� ������ 1�� �����ϸ�, ������ ���� ������ 1�� �����Ѵ�.
   ���� ������ shared_ptr�� ������ ���Ͽ�, ���� Ƚ���� 0�� �Ǹ� delete Ű���带 ����Ͽ� �޸𸮸� �ڵ����� �����Ѵ�.
*/

class Person
{
private:
    string name_;
    int age_;
public:
    Person(const string& name, int age);
    ~Person() { cout << "�Ҹ��� ȣ��" << endl; }
    void ShowPersonInfo();
};

Person::Person(const string& name, int age)
{
    name_ = name;
    age_ = age;
    cout << "������ ȣ��" << endl;
}

void Person::ShowPersonInfo()
{
    cout << name_ << "�� ���̴� " << age_ << "���Դϴ�." << endl;
}

int main()
{
    shared_ptr<int> ptr01(new int(5));
    // shared_ptr ��ü�� ���� ����Ű�� �ִ� ���ҽ��� ���� ���� �������� ���� ��ȯ
    cout << ptr01.use_count() << endl; 

    auto ptr02(ptr01); // ���� �����ڸ� �̿��� �ʱ�ȭ
    cout << ptr01.use_count() << endl;

    auto ptr03 = ptr01; // ������ ���� �ʱ�ȭ
    cout << ptr01.use_count() << endl;

    shared_ptr<Person> hong = make_shared<Person>("�浿", 29);
    cout << "���� ������ �� : " << hong.use_count() << endl;
    auto han = hong;
    cout << "���� ������ �� : " << hong.use_count() << endl;
    han.reset(); // shared_ptr�� han �� ������.
    cout << "���� ������ �� : " << hong.use_count() << endl;
    return 0;
}