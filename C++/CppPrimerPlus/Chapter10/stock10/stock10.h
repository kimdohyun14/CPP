// stock10.h -- 생성자들과 소멸자가 추가된 Stock 클래스 선언
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock(); // 디폴트 생성자
	Stock(const std::string& co, long n = 0, double pr = 0.0);
	~Stock(); // 소멸자
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};
#endif