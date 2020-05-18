#include <iostream>
using namespace std;

// C++ ���� ���

/* ���� ���(Static Member)�� Ŭ�������� ���� �Ǿ� �ִ� ��������� ��� ��ü�� �����ϴ� ����̴�.
   �������� ����� ����� �޸� �� ���� �ϳ��� �Ҵ�Ǿ� �����ȴ�.
   
   ���� ����� public���� �����ϸ� �ܺ��� ��� Ŭ�������� ������ �����ϸ�, ���� �ϳ��� �����ȴ�.
   ���� ����� �Ϲ������� �̱��� ����(Singleton Pattern) ���� �پ��� ����� ���� ���ȴ�. */

class Person
{
private:
    string name;
public:
    static int count;
    Person(string name) : name(name)
    {
        count++;
    }
};

int Person::count = 0; // Person�̶�� Ŭ���� ��ü�� �����ϴ� count ���� ������ ���� 0���� �ʱ�ȭ

int main()
{
    Person p1("AAA");
    Person p2("BBB");
    Person p3("CCC");
    cout << "����� �� : " << Person::count << '\n';
    return 0;
}