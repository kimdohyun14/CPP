#include <iostream>
#include <memory>
using namespace std;

/* smart pointer
   
   C++ ���α׷����� new Ű���带 ����ؼ� �������� �Ҵ�޴� �޸𸮴� �ݵ�� delete�� �����ؾ� �Ѵ�.
   ���α׷��� �������� �����ϱ� ���� ����Ʈ �����͸� �����ϰ� �ִ�.
   
   ����Ʈ �����Ͷ� ������ó�� �����ϴ� Ŭ���� ���ø�����, ����� ���� �޸𸮸� �ڵ����� ������ �ش�.
   
   ���⼭�� unique_ptr�� �ϳ��� ����Ʈ �����͸��� Ư�� ��ü�� ������ �� �ֵ���, ��ü�� ������ ������ ������
   ����Ʈ �������̴�.
   
   �� ����Ʈ �����ʹ� �ش� ��ü�� �������� ������ ���� ����, �Ҹ��ڰ� �ش� ��ü�� ������ �� �ִ�.
   unique_ptr �ν��Ͻ��� move() ��� �Լ��� ���� �������� ������ �� ������, ����� �� �� ����.
   �������� �����Ǹ�, ���� unique_ptr �ν��Ͻ��� ���� �ش� ��ü�� �������� �ʰ� �缳���ȴ�.
*/

// C++ ��ü�� ���� ����Ʈ �����Ͱ� �ʿ��� ��Ȳ���� �ַ� unique_ptr�� ����Ѵ�.

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

int main()
{
	unique_ptr<Person> hong = make_unique<Person>("�浿", 29);
	hong->ShowPersonInfo();
	/* Person ��ü�� ����Ű�� unique_ptr �ν��Ͻ��� hong �� �Ϲ� �����Ϳ� �޸�
	   ����� ���� �Ŀ� delete Ű���带 ����Ͽ� �޸𸮸� ������ �ʿ䰡 ����. 
	   
	   make_unique()�Լ��� C++ 14���� �����ϴ�.*/
	return 0;
}

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