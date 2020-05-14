// ���Ҽ� (Complex number) Ŭ���� �����
// C++ ǥ�� ���̺귯���� std::complex�� ���ǵǾ� �ִ�.

// ���Ҽ��� ����� �Ǽ��� ������ ǥ��
// z = a + bi (a, b�� ��� �Ǽ�)

// ���Ҽ��� ��Ģ ������ �Ǽ��ο� ����η� ���� �����Ѵ�.
// ��� ���� ���ϸ� �ٽ� -1�� �ȴ�.

// �������� �����ε��� �𸥴ٰ� ����
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
// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
// ���ڿ��� ���� ������ ����. "[��ȣ](�Ǽ���)[��ȣ]i(�����)"
// �� �� �� ���� ��ȣ�� ���� �����ϴ�. (+�� ��)

	int begin = 0, end = strlen(str);
	img = 0.0, real = 0.0;

	// ���� ���� ������ �Ǵ� i�� ��ġ�� ã�´�.
	int pos_i = -1;
	for (int i = 0; i != end; ++i) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// ���� i �� ���ٸ� �� ���� �Ǽ��̴�.
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	// ���� i �� �ִٸ�, �Ǽ��ο� ����θ� ����� ó���Ѵ�.
	real = get_number(str, begin, pos_i - 1);
	img = get_number(str, pos_i + 1, end - 1);

	// �����̸� ���� ó���Ѵ�.
	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

// a + b / c + d;
// a.plus(b.divide(c)).plus(d); �� ���� ����, �������� ���ϵȴ�.

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

// ��Ģ ������ ��� �ݵ�� ���� �����ؾ��Ѵ�.

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



// ���� ������ �Լ��� ���� Ÿ���� ���������� �����Ѵ�.
// ���� if ((i = x) < y ) �� ���� ������ ����ϱ� ������
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

// ������ �����ε��� ����ϸ�, a += b �� a = a + b�� ���ٰ� ������� �ʴ´�.
// �� ���� operator+ �� operator= �� �����ߴٰ� �ؼ� a += b�� �ڵ����� �Ǵ� ���� �ƴ϶�
// operator+=�� ���� ������ �۵��Ѵ�.


double Complex::get_number(const char* str, int from, int to) {
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;      // �Ҽ��� �� �κ�
	double decimal = 1.0;  // �Ҽ��� �� �κ�

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
			break; // �� ���� �̻��� ���ڵ��� �� ����
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

// operator= �� ������ �ʴ���, �� �۵��Ѵ�.
// �����Ϸ� �������� ����Ʈ ���� �����ڸ� �����ϱ� ������
// �ٸ�, ���� ���縦 �����ϹǷ� ���� ���簡 �ʿ��� ���
// (Ŭ���� ���������� �������� �Ҵ�Ǵ� �޸𸮸� �����ϴ� �����Ͱ� �ִٸ�)
// ���� ������ �Լ��� ���� �����ؾ��Ѵ�.

// Some_Class a = b
// a �� ���� �����ڰ� ȣ��Ǵ� ��

// Some_Class a;
// a = b;
// a �� �⺻ �����ڰ� ȣ��� ����, ���� ������ �Լ��� ����ȴ�.