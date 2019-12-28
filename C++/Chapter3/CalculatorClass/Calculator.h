#pragma

class Calculator {
private:
	int addCnt;
	int minCnt;
	int mulCnt;
	int divCnt;
public:
	void init();
	double Add(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
	double Div(double a, double b);
	void ShowOpCount();
};