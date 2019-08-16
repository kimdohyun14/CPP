// 복소수 (Complex number) 클래스 만들기
// C++ 표준 라이브러리에 std::complex가 정의되어 있다.

// 복소수는 허수와 실수의 합으로 표현
// z = a + bi (a, b는 모두 실수)

// 복소수의 사칙 연산은 실수부와 허수부로 따로 진행한다.
// 허수 둘을 곱하면 다시 -1로 된다.

// 연산자의 오버로딩을 모른다고 가정
#include <iostream>

class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to);

public:
	Complex(double real, double img) : real(real), img(img) { }
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	//Complex puls(const Complex& c);
	//Complex minus(const Complex& c);
	//Complex times(const Complex& c);
	//Complex divide(const Complex& c);
	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex& operator=(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex operator+(const char* str);
	Complex operator-(const char* str);
	Complex operator*(const char* str);
	Complex operator/(const char* str);

	void println() { std::cout << "( " << real << " , " << img << " )" << std::endl; }
	
};

Complex::Complex(const char* str) {
// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
// 문자열의 꼴은 다음과 같다. "[부호](실수부)[부호]i(허수부)"
// 이 때 맨 앞의 부호는 생략 가능하다. (+일 시)

	int begin = 0, end = strlen(str);
	img = 0.0, real = 0.0;

	// 먼저 가장 기준이 되는 i의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; ++i) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// 만일 i 가 없다면 이 수는 실수이다.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// 만일 i 가 있다면, 실수부와 허수부를 나누어서 처리한다.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	// 음수이면 음수 처리한다.
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

// a + b / c + d;
// a.plus(b.divide(c)).plus(d); 딱 봐도 복잡, 가독성이 저하된다.

Complex Complex::operator+(const Complex& c) {
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) {
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) {
	Complex temp(real * c.real - img * c.img, real * c.img + c.real * img);
	return temp;
}

Complex Complex::operator/(const Complex& c) {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

// 사칙 연산의 경우 반드시 값을 리턴해야한다.

Complex Complex::operator+(const char* str) {
	Complex temp(str);
	return (*this) + temp;
}
Complex Complex::operator-(const char* str) {
	Complex temp(str);
	return (*this) - temp;
}
Complex Complex::operator*(const char* str) {
	Complex temp(str);
	return (*this) * temp;
}
Complex Complex::operator/(const char* str) {
	Complex temp(str);
	return (*this) / temp;
}



// 대입 연산자 함수는 리턴 타입이 참조형으로 리턴한다.
// 종종 if ((i = x) < y ) 와 같은 문장을 사용하기 때문에
Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
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

// 연산자 오버로딩을 사용하면, a += b 와 a = a + b가 같다고 보장되지 않는다.
// 이 말은 operator+ 와 operator= 를 정의했다고 해서 a += b가 자동으로 되는 것이 아니라
// operator+=를 따로 만들어야 작동한다.


double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;      // 소수점 앞 부분
	double decimal = 1.0;  // 소수점 뒷 부분

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
			break; // 그 외의 이상한 문자들이 올 경우는
	}

	if (minus) num *= -1.0;

	return num;
}

int main() {

	Complex a(0, 0);
	a = a + "-1.1 + i3.923";
	a.println();
	a = a - "1.2 - i1.823";
	a.println();
	a = a * "2.3 + i22";
	a.println();
	a = a / "-12 + i55";
	a.println();

	return 0;
}

// operator= 를 만들지 않더라도, 잘 작동한다.
// 컴파일러 차원에서 디폴트 대입 연산자를 지원하기 때문에
// 다만, 얕은 복사를 수행하므로 깊은 복사가 필요한 경우
// (클래스 내부적으로 동적으로 할당되는 메모리를 관리하는 포인터가 있다면)
// 대입 연산자 함수를 직접 정의해야한다.

// Some_Class a = b
// a 의 복사 생성자가 호출되는 것

// Some_Class a;
// a = b;
// a 의 기본 생성자가 호출된 이후, 대입 연산자 함수가 수행된다.