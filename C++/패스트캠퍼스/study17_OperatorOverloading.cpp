#include <iostream>
using namespace std;

// C++ ������ �����ε�

/* ������ �����ε� ������ Ȱ���� ������ ���� ���ϴ� ������� �����Ͽ� ����� �� �ִ�.

   1. ������ �����ϴ� �����ڸ� ������ �� �ִ�.
   2. ��� ������ (.), ���� ���� ������ (::) ���� ��� �����ڴ� �����ε� ó���� �� ����.
   3. �ǿ������� ���� ��Ģ �� �⺻���� �������� ��Ģ�� ������Ѵ�.
   4. �����ε��� �� �������� �ǿ����� �� �ϳ��� ����� ���� �ڷ��� �̾�߸� �Ѵ�. */

class Person
{
private:
    string name;
public:
    Person() { name = "dohyun"; }
    Person(string name) : name(name) { }
    Person operator +(const Person& other) { return Person(name + " & " + other.name); }
    void showName() { cout << "�̸�: " << name << '\n'; }
};

int main()
{
    Person person1;
    Person person2("doing");
    // Ư���� Person�� �ٸ� Person�� + �Ѵٰ� �Ѵٸ�?
    Person result = person1 + person2;
    result.showName();
    return 0;
}