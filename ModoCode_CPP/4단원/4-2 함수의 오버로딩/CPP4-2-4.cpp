//Date 클래스
#include <iostream>

//보통 간단한 함수를 제외하면 대부분의 함수들은 클래스 바깥에서 정의한다.
//디폴트 생성자 정의해보기
//생성자 오버로딩도 가능하다.
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

	//디폴트 생성자(Default Constructor)
	//클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않을 때
	Date() {
		year = 2012;
		month = 7;
		day = 12;
	}

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
	Date day = Date();
	Date day2;

	day.show_date();
	day2.show_date();

	//day3 객체를 디폴트 생성자를 이용해서 초기화 하는 것이 아니라,
	//리턴값이 Date이고 인자가 없는 함수 day3을 정의하게 된 것으로 인식
	//이는 암시적 표현
	Date day3();
	return 0;
}