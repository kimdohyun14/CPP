#include <iostream>
using namespace std;

//����
class Base {
public:
	void Print() {
		cout << "From Base!!" << endl;
	}
};

//�Ѱ�
class Derived : public Base {
public:
	void Print() {
		cout << "From Derived!!" << endl;
	}
};

class Derived2 : public Base {
public:

};

int main() {
	//���� ���ε� : ������ �ð��� ������
	//cpp�� �⺻ ���ε��� ���� ���ε�, Ÿ���� ���� ����.
	//java�� �⺻ ���ε��� ���� ���ε�, final�� ���̸� ���� ���ε��� �ȴ�.
	Base *b = new Derived();
	b->Print();
	delete b;

	b = new Derived2();
	b->Print();
	delete b;

	return 0;
}