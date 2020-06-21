#include <iostream>
#include <cstring>

class Complex
{
private:
	double real, img;

	double get_number(const char* str, int from, int to);

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }

	Complex operator+(const Complex& c);
	Complex operator+(const char* str);

	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);

	Complex& operator=(const Complex& c);

	void println() { std::cout << "( " << real << " , " << img << " )" << std::endl; }
};

double Complex::get_number(const char* str, int from, int to)
{
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++)
	{
		if (isdigit(str[i]) && integer_part)
		{
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
		{
			integer_part = false;
		}
		else if (isdigit(str[i]) && !integer_part)
		{
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else
		{
			break; // 이상한 문자들이 올 경우
		}
	}

	if (minus) num *= -1.0;
	return num;
}

Complex Complex::operator+(const Complex& c)
{
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator+(const char* str)
{
	int begin = 0, end = strlen(str);
	double str_real = 0.0, str_img = 0.0;

	// 기준이 되는 'i' 의 위치를 찾는다.
	int pos_i = -1;
	for (int i = 0; i != end; i++)
	{
		if (str[i] == 'i')
		{
			pos_i = i;
			break;
		}
	}

	// 'i' 가 없다면 이 수는 실수다.
	if (pos_i == -1)
	{
		str_real = get_number(str, begin, end - 1);

		Complex temp(str_real, str_img);
		return (*this) + temp;
	}

	// 만일 'i' 가 있다면, 실수부와 허수부로 나누어서 처리하자.
	str_real = get_number(str, begin, pos_i - 1);
	str_img = get_number(str, pos_i + 1, end - 1);

	// 허수부의 부호를 체킹
	if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

	Complex temp(str_real, str_img);
	return (*this) + temp;
}

Complex Complex::operator-(const Complex& c)
{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c)
{
	// a1a2 - b1b2 + i(a1b2 + a2b1)
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c)
{
	// a1a2 + b1b2 + i(a2b1 - a1b2)
	// ----------------------------
	//         a2a2 + b2b2
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
	);
	return temp;
}

Complex& Complex::operator+=(const Complex& c)
{
	(*this) = (*this) + c;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	(*this) = (*this) - c;
	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	(*this) = (*this) * c;
	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	(*this) = (*this) / c;
	return *this;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

int main()
{
	Complex a(0, 0);
	a = a + "-1.1 + i3.923";
	a.println();
	return 0;
}