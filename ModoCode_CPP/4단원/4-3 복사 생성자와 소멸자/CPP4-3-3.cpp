//�Ҹ��� ȣ�� Ȯ���ϱ�
#include <cstring>
#include <iostream>

class Test {
	char c;

public:
	Test(char _c) {
		c = _c;
		std::cout << "������ ȣ��" << c << std::endl;
	}
	~Test() {
		std::cout << "�Ҹ��� ȣ��" << c << std::endl;
	}
};

//���� ��ü�̱� ������ simple_function�� ����ʰ� ���ÿ�
//b ���� �Ҹ�ǰ� �ȴ�. -> b�� �Ҹ��ڰ� ȣ���
void simple_function() {
	Test b('b');
}

int main() {
	Test a('a');
	simple_function();
	return 0;
}

//main�Լ��� ���� ��ü���� a�� �Ҹ�Ǹ鼭 a�� �Ҹ��ڰ� ȣ��ȴ�.
//��� a - b - b - a
//������ ���̿��� lock �� ���� Ǫ�� ���ҵ� �����Ѵ�.
//�Ҹ��ڵ� ����Ʈ �Ҹ��ڰ� �ִ�.
//�Ҹ��ڰ� �ʿ� ���� Ŭ������� ���� �Ҹ��ڸ� ���� ���� �ʿ䰡 ����.