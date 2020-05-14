// 멤버 함수가 아닌 연산자 함수 오버로딩
// 입출력 연산자 오버로딩 <<, >> 연산자
// 첨자 연산자 [] 오버로딩
// 타입 변환 연산자 오버로딩
// 증감 연산자, ++, -- 오버로딩

#include <cstring>
#include <iostream>

class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to);

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex& operator=(const Complex& c);

	//private 나 public이나 관계없이 이 함수는 Complex 객체라도 그 내부 정보를 접근 가능하다.
	friend Complex operator+(const Complex& a, const Complex& b);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);

	void println() {
		std::cout << "( " << real << " , " << img << " ) " << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}

// 클래스 내부 함수에 없는 외부 함수이다.
// 직접적으로는 Complex의 클래스의 private 영역에 있는 것에 접근이 불가능 하지만,
// friend 관계이면 접근이 가능하게 된다.
Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str) {
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;

	// 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// 만일 'i' 가 없다면 이 수는 실수 뿐이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part = false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
			break;  // 그 이외의 이상한 문자들이 올 경우
	}

	if (minus) num *= -1.0;

	return num;
}
Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

Complex& Complex::operator+=(const Complex& c) {
	(*this) = (*this) + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	(*this) = (*this) - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	(*this) = (*this) * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	(*this) = (*this) / c;
	return *this;
}
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}

int main() {
	Complex a(0, 0);
	a = "-1.1 + i3.923" + a;
	std::cout << "a 의 값은 : " << a << " 이다." << std::endl;
}


/*
class A{
private:
	int x;

	friend B;
};

class B{
private:
	int y;
};
*/

// A 는  B 를 friend로 지정합니다.
// A 는 자기 생각에 B가 friend라고 생각하는 것이므로,
// B 에게 A 의 모든 것을 공개한다.
// B는 A의 변수 X에 접근이 가능하다.
// 단, B 에서는 A를 friend로 지정하지 않았으므로, A는 B의 일부분만 접근 가능하다.(public)


// 입출력 연산자 오버로딩
// std::cout << a;

// std::cout.operator<<(a) 를 하는 것과 동일한 명령이다.