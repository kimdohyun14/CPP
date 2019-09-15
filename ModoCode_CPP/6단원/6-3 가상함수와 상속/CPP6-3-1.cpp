// �����Լ��� ��ӿ� ������ �����

// virtual �Ҹ���(���� �Ҹ���)
// ���� �Լ� ���̺� (virtual function table)
// ���� ���
// ���� ���

// virtual �Ҹ���
// Ŭ������ ����� ��������ν� �߿��ϰ� ó���ؾ� �Ǵ� �κ���
// ��� �ÿ�, �Ҹ��ڸ� �����Լ��� ������ �Ѵ�.
#include <iostream>

class Parent {
public:
	Parent() {
		std::cout << "Parent ������ ȣ��" << std::endl;
	}
	virtual ~Parent() {
		std::cout << "Parent �Ҹ��� ȣ��" << std::endl;
	}
};

class Child : public Parent {
public:
	Child() {
		std::cout << "Child ������ ȣ��" << std::endl;
	}
	~Child() {
		std::cout << "Child �Ҹ��� ȣ��" << std::endl;
	}
};

int main() {
	// ����
	std::cout << "--- ����� Child ������� �� ---" << std::endl;
	{ Child c; }
	
	// Child�� �Ҹ��ڰ� ȣ����� �ʴ´�.
	// �Ҹ��ڰ� ȣ����� �ʴ´ٸ� �������� ������ ���� �� �ִ�.
	// ���࿡ Child ��ü���� �޸𸮸� �������� �Ҵ��ϰ� �Ҹ��ڿ��� �����ϴµ�,
	// �Ҹ��ڰ� ȣ�� �ȉ�ٸ� �޸� ����(memory leak)�� �����.

	// �ذ�� �ܼ��� Parent�� �Ҹ��ڸ� virtual�� ���������� �ȴ�.
	// �̴� Child �Ҹ��ڸ� ȣ���ϸ鼭 Child �Ҹ��ڰ� �˾Ƽ� Parent �Ҹ��ڸ� ȣ���ϹǷ�
	// Parent �Ҹ��ڸ� ���� ȣ���ϰ� �Ǹ�, Parent�� Child�� �ִ��� ������ �𸣹Ƿ�,
	// Child �Ҹ��ڸ� ȣ������ �� ����. �׷��� ������ �����.
	// �׷��� Base Ŭ�������� �ݵ�� �Ҹ��ڸ� virtual�� ������־�� ���߿� ������ �߻����� �ʴ´�.
	std::cout << "--- Parent �����ͷ� Child �������� ��" << std::endl;
	{
		Parent* p = new Child();
		delete p;
	}
}