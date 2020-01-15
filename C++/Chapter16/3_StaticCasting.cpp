#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{ }
	void ShowCarState() { cout << "잔여 연료량: " << fuelGauge << endl; }
};

class Truck : public Car
{
private:
	int freightWeight;
public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
	{ }
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

// static_cast : A 타입에서 B 타입으로
// 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환
// 기초 클래스의 포인터 및 참조형 데이터를 유도 클래스의 포인터 및 참조형 데이터로 형 변환
// 양방향이 가능하다. 다만, 그에 따른 책임은 작성한 자가 진다.

// derived class -> Base class로 형 변환을 의미, 단 두 클래스는 서로 상속관계여야 한다.
// Base class - > derived class로도 가능하다.

// static_cast 연산자는 dynamic_cast 연산자보다 연산의 속도가 빠르다.
// 그래서 dynamic_cast 연산자를 사용하는 상황에서도 static_cast를 사용하기도 한다.

// 기본 자료형 간의 형 변환, 클래스의 상속관계에서의 형 변환만 허용한다.
// 기존 C언어의 형 변환 연산자는 말도 안 되는 형 변환도 허용하므로, static_cast 연산자의 사용은 의미를 가지게 된다.

int main()
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
    Truck* ptruck2 = static_cast<Truck*>(pcar2);
	ptruck2->ShowTruckState();
	return 0;
}