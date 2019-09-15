// ���۷����� �ȴ�.

// ���±��� ��� Ŭ�������� �Ļ� Ŭ������ �Լ��� ������ ��
// �׻� ��� Ŭ������ �����͸� ���ؼ� ����������,
// ��� ��� Ŭ������ ���۷������� ���� ���� �۵��Ѵ�.
#include <iostream>

class A {
public:
	virtual void show() {
		std::cout << "Parent !" << std::endl;
	}
};

class B : public A {
public:
	void show() override {
		std::cout << "Child !" << std::endl;
	}
};

// test �Լ������� A Ŭ������ ���۷����� �ް� �Ǿ� ������,
// ���� �۵��Ѵ�.
// B Ŭ������ A Ŭ������ ��ӹް� �ֱ� ������
// ���� test �Լ����� show()�� ȣ���Ͽ��� �� ���ڷ� b�� �����ߴٸ�,
// ��� ���޵� ���ڰ� A�� ��ü��� ǥ���Ǿ� ������ show �Լ��� virtual����
// ���ǵǾ� �ֱ� ������ �˾Ƽ� B�� show �Լ��� ã�Ƴ��� ȣ���ϰ� �ȴ�.
void test(A& a) {
	a.show();
}

int main() {
	A a;
	B b;
	test(a);
	test(b);

	return 0;
}