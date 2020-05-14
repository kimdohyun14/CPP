#include <iostream>

//��ü������ ����
class Animal {
	//��� ����
	//��ü �ȿ����� ���� ���� (�ܺ� x)
private:
	int food;
	int weight;

	//��� �Լ�
	//�ܺο��� ������ ����� ����
public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}

	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}

	void view_stat() {
		std::cout << "�� ������ food : " << food << std::endl;
		std::cout << "�� ������ weight : " << weight << std::endl;
	}
};

int main() {
	Animal animal; //�ν��Ͻ��� ������ ��ü
	animal.set_animal(100, 50); 
	animal.increase_food(30);//������ ~�Դ´�.

	animal.view_stat();
	return 0;
}