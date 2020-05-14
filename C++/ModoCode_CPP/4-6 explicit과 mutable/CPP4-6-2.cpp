// mutable Ű����
// const �Լ� ���ο����� ��� �������� ���� �ٲٴ� ���� �Ұ����ϴ�.
// ���࿡ ��� ������ mutable �� �����Ѵٸ�, const�Լ������� ���� �ٲ� �� �ִ�.

#include <iostream>

class A {
	mutable int data_;

public:
	A(int data) : data_(data) { }
	void DoSomething(int x) const {
		data_ = x; //�Ұ���!
	}

	void PrintData() const {
		std::cout << "data : " << data_ << std::endl;
	}
};

int main() {
	A a(10);
	a.DoSomething(3);
	a.PrintData();
	return 0;
}

// ��� �Լ��� const�� �����ϴ� �ǹ̴� 
// �� �Լ��� ��ü�� ���� ���¿� ������ ���� �ʽ��ϴٸ� ǥ���ϴ� ���
// �б� �۾��� �����ϴ� �Լ���


// mutable�� ���� ����
// �б� �۾��� �����ϴ� �Լ� �߿��� const�� ���⿡�� ������� ���忡��
// �翬�� const�� ���ǵǾ���ϴ� �Լ��̱� ������,
// �б� �۾��� �����ϴ� �Լ� �ȿ���
// ĳ�ø� ������Ʈ�� �� mutable�� �����ع����� �ȴ�.