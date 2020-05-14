// 순수 가상 함수(pure virtual function)와 추상 클래스(abstract class)
#include <iostream>

// 순수 가상 함수를 최소 한개 포함하고 있는 클래스
// 반드시 상속 되어야 하는 클래스를 가리켜 추상 클래스(abstract class)라고 한다.

// 추상 클래스를 왜 사용하는 것일까?
// 추상 클래스 자체로는 인스턴스화 시킬 수 없고,
// 사용하기 위해서는 반드시 다른 누군가 상속 해줘야만 한다.
// 추상 클래스를 설계도라고 생각하면 좋다.

// 이 클래스를 상속받아서 사용하는 사람에게 "이 기능은 일반적인 상황에서 만들기 힘드니,
// 너가 직접 특수화 되는 클래스에 맞추어서 만들어서 쓰라고" 말해주는 것이다.

// 추상 클래스의 또 한가지 특징은 비록 객체는 생성할 수 없지만,
// 추상 클래스를 가리키는 포인터는 문제없이 만들 수 있다.
// Animal* dog = new Dog();
// Animal* cat = new Cat();
class Animal {
public:
	Animal(){ }
	virtual ~Animal() { }

	// 다른 함수들과 달리, 함수의 몸통이 정의되어 있지 않고
	// 단순히 = 0; 으로 처리되어 있는 가상함수이다.
	// 무엇을 하는지 정의되어 있지 않은 함수
	// 이 함수는 반드시 오버라이딩 되어야만 하는 함수이다.
	// 반드시 오버라이딩 되도록 만든 함수를 완전한 가상 함수라 해서,
	// 순수 가상 함수(pure virtual function)라고 부른다.
	virtual void speak() = 0;
	// 동물들의 소리는 제 각각 다르기 때문에
	// speak()를 가상 함수로 만들기는 불가능하다.
	// 따라서 speak()를 순수 가상 함수로 만들고, 이를 상속하는 클래스에서
	// 그 클래스의 상황에 맞게 구현하면 된다.
	// Dog은 왈왈
	// Cat은 야옹야옹 처럼
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
	// 아예 Animal의 객체 생성을 금지한다. (이는 Animal의 인스턴스를 생성하지 못하게 한다.)
	// 이 객체는 순수 가상 함수를 포함하고 있기 때문에
	//Animal a;
	//a.speak();
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
	return 0;
}