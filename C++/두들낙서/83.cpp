// ��ӿ����� ����ȯ - �ٿ�ĳ����
// static_cast
// �������� ��ȯ ������ Ÿ���� ��ȯ�Ѵ�.
// ������ Ÿ�ӿ� ����ȯ�� ���� Ÿ�� ������ ����ش�.
// double -> int / int -> double
// �ٿ�ĳ���� / ��ĳ����
// ������ �ð��� �Ϸ�� (����)

#include <iostream>
using namespace std;

class Base {
public:
	int a = 1;
};

class Drv1 : public Base {
public:
	float b = 3.14;

	void f() {
		cout << "Drv1::f()" << endl;
		cout << b << endl;
	}
};

class Drv2 : public Base {
public:
	int c = 3;

	void f() {
		cout << "Drv2::f()" << endl;
		cout << c << endl;
	}
};

int main() {
	Base* b = new Drv1;
	int* a = new int(5);
	// ���� �ȵǴ� ����ȯ�� �����ش�.
	//Drv1* d1 = static_cast<Drv1*>(a);
	Drv1* d1 = static_cast<Drv1*>(b);
	d1->f();

	// ������ : �����Ϸ������� ������ �Ⱥ��δ�.
	// ���������� b�� Drv1�� ����Ű�� �ִµ�,
	// ���⼭�� b�� Drv2�� �ٿ�ĳ�����ϰ� ����.
	// �� d2�� b�� ����Ű�� ���� ����Ű�� ����
	// Drv2 != Drv1
	Drv2* d2 = static_cast<Drv2*>(b);
	d2->f();

	delete b;
}