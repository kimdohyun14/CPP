// 상속에서의 형변환 - RTTI, dynamic_cast
// static_cast: 정적(컴파일)
// dynamic_cast: 동적(런타임)
// RTTI (Run Time Type Information/Identification)

// dynamic_cast
// 런타임 시간에 실제로 해당 타입이 다운 캐스팅이 가능한지 검사하기 때문에
// 런타임 비용이 조금 높은 캐스트 연산자다.
// 최대한 안하는 방향으로 클래스를 설계하는 것이 좋다.
// 캐스팅 성공: new_type의 value를 리턴
// 캐스팅 실패: null pointer를 리턴
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
	virtual double GetArea() const = 0;
	virtual void Resize(double k) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}
	double GetArea() const {
		return r * r * 3.14;
	}
	void Resize(double k) {
		r *= k;
	}
private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a),b(b) {}
	double GetArea() const {
		return a * b;
	}
	void Resize(double k) {
		a *= k;
		b *= k;
	}
	double GetDiag() const {
		return sqrt(a * a + b * b);
	}
private:
	double a, b;
};

int main() {
	Shape* shapes[] = { // 포인터 배열, 동적으로 할당하지 않아서 해제는 안함.
		// 나머지 요소들은 각각 동적할당을 했으므로 나중에 할당해제를 해줘야함.
		new Circle(1),
		new Rectangle(1,2)
	};

	for (int i = 0; i < 2; i++) {
		// 도형의 넓이
		// 만약 직사각형일 경우, 대각선 길이 출력
		cout << "도형의 넓이 : " << shapes[i]->GetArea() << endl;
		Rectangle* r = dynamic_cast<Rectangle*>(shapes[i]);
		if (r != NULL) {
			cout << "대각선의 길이: " << r->GetDiag() << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
	return 0;
}