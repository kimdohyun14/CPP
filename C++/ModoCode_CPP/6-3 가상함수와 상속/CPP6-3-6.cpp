// ���� ��� �� ������ ��
#include <iostream>

class A {
public:
	int a;
};

class B {
public:
	int a;
};

class C : public B, public A {
public:
	int c;
};

int main() {
	C c;
	//c.a = 3;
	return 0;
}

// �ߺ��Ǵ� ��� ������ �����ϸ�
// B�� a����, A�� a���� ������ �� ���ٴ� ������ �߻��Ѵ�.

// ����������, Ŭ���� A�� B�� ���� �̸��� �Լ��� �ִٸ� ������ �߻�
// ������ �Ȱ��� � �Լ��� ȣ���ؾ� �� �� ������ �� �����Ƿ�