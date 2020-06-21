#include <iostream>

class Complex
{
private:
	double real, img;

public:
	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }

	Complex operator+(const Complex& c);
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);

	Complex& operator=(const Complex& c);

	void println() { std::cout << "( " << real << " , " << img << " )" << std::endl; }
};

Complex Complex::operator+(const Complex& c)
{
	Complex temp(real + c.real, img + c.img);
	return temp;
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


Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}


int main()
{
	Complex a(1.0, 2.0);
	Complex b(3.0, -2.0);
	Complex c(0.0, 0.0);

	c = a * b + a / b + a + b;

	c.println();
	return 0;
}