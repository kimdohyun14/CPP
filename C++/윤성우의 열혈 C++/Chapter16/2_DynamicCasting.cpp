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

// dynamic_cast : 상속관계에서 안전한 형 변환
// 유도 클래스의 포인터 및 참조형 데이터를 기초 클래스의 포인터 및 참조형 데이터로 형 변환
// 그게 아니라면 컴파일 에러 발생

// derived class -> Base class로 형 변환을 의미, 단 두 클래스는 서로 상속관계여야 한다.

int main()
{
	Car* pcar1 = new Truck(80, 200);
	//Truck* ptruck1 = dynamic_cast<Truck*>(pcar1);

	Car* pcar2 = new Car(120);
	//Truck* ptruck2 = dynamic_cast<Truck*>(pcar2);

	Truck* ptruck3 = new Truck(70, 150);
	Car* pcar3 = dynamic_cast<Car*>(ptruck3);
	pcar3->ShowCarState();
	return 0;
}