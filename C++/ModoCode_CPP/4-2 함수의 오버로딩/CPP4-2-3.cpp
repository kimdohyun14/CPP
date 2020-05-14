//Date 클래스
#include <iostream>

//보통 간단한 함수를 제외하면 대부분의 함수들은 클래스 바깥에서 정의한다.
class Date {
	int year;
	int month;
	int day;

public:
	void set_data(int _year, int _month, int _date);
	void add_day(int inc);
	void add_month(int inc);
	void add_year(int inc);
	void show_date();

	//생성자(Constructor)
	//생성->초기화 (간혹 실수로 초기화를 안하는 실수방지)
	//객체 생성시 자동으로 호출되는 함수
	//객체를 초기화 하는 역할을 하기에 리턴값이 없다.
	Date(int _year, int _month, int _day) {
		year = _year;
		month = _month;
		day = _day;
	}
};

void Date::set_data(int _year, int _month, int _day) {
	year = _year;
	month = _month;
	day = _day;
}

void Date::add_day(int inc) {
	int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i = month;

	if (month_day[i - 1] - day >= inc) {
		day += inc;
		return;
	}
	else {
		add_month(1);
		day = 1;

		inc = inc - (month_day[i - 1] - day) - 1;
		i++;
	}

	while (true) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			month_day[1] = 29; //윤년
		}
		else {
			month_day[1] = 28;
		}

		//만약에 그 달을 추가할 수 있다면
		if (inc - month_day[i - 1] >= 0) {
			add_month(1);
			inc = inc - month_day[i - 1];
		}
		else if (inc - month_day[i - 1] < 0) {
			day = day + inc;
			break;
		}

		i++;
		if (i > 12) i = i - 12;
	}
}

void Date::add_month(int inc) {
	add_year((inc + month - 1) / 12);
	month = month + inc % 12;
	month = (month == 12 ? 12 : month % 12);
}

void Date::add_year(int inc) { year += inc; }

void Date::show_date() {
	std::cout << "오늘은 " << year << " 년 " << month << " 월 " << day << " 일 입니다 " << std::endl;
}

int main() {
	Date day(2011, 3, 1); //생성자에 의한 초기화(암시적 초기화) implicit
	//Date day = Date(2011, 3, 1); //(명시적 초기화) explicit
	day.show_date();

	day.add_year(10);
	day.show_date();
	return 0;
}