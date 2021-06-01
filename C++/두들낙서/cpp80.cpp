//순수 가상 함수와 추상 클래스
#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

//추상 클래스는 그 자체만으로는 의미없지만
//상속을 받아 오버라이딩 하는 순간 의미가 생긴다.
//추상 클래스는 그 자체만으로 인스턴스를 만들 수 없다.
class Shape {
public:
	//구체적인 수치를 가지고 있지 않을 때, 순수 가상 함수를 사용하면 애매함을 방지할 수 있다.
	virtual double GetArea() = 0;
	virtual void Resize(double f) = 0;
};

class Circle : public Shape{
public:
	Circle(double r) : r(r) {}

	double GetArea() {
		return PI * r * r;
	}
	void Resize(double f) {
		r *= f;
	}
private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() {
		return a * b;
	}

	void Resize(double f) {
		a *= f;
		b *= f;
	}
private:
	double a, b;
};

int main() {
	Shape* shapes[] = {
		new Circle(10),
		new Rectangle(20, 30)
	};

	for (Shape* s : shapes) {
		s->Resize(2);
	}

	for (Shape* s : shapes) {
		cout << s->GetArea() << endl;
	}

	for (Shape* s : shapes) {
		delete s;
	}
	return 0;
}