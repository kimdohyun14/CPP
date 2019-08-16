#include <iostream>

//객체지향의 시작
class Animal {
	//멤버 변수
	//객체 안에서만 직접 접근 (외부 x)
private:
	int food;
	int weight;

	//멤버 함수
	//외부에서 마음껏 사용이 가능
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
		std::cout << "이 동물의 food : " << food << std::endl;
		std::cout << "이 동물의 weight : " << weight << std::endl;
	}
};

int main() {
	Animal animal; //인스턴스로 생성된 객체
	animal.set_animal(100, 50); 
	animal.increase_food(30);//동물이 ~먹는다.

	animal.view_stat();
	return 0;
}