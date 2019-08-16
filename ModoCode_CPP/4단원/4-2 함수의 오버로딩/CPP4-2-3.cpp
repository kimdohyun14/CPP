//Date Ŭ����
#include <iostream>

//���� ������ �Լ��� �����ϸ� ��κ��� �Լ����� Ŭ���� �ٱ����� �����Ѵ�.
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

	//������(Constructor)
	//����->�ʱ�ȭ (��Ȥ �Ǽ��� �ʱ�ȭ�� ���ϴ� �Ǽ�����)
	//��ü ������ �ڵ����� ȣ��Ǵ� �Լ�
	//��ü�� �ʱ�ȭ �ϴ� ������ �ϱ⿡ ���ϰ��� ����.
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
			month_day[1] = 29; //����
		}
		else {
			month_day[1] = 28;
		}

		//���࿡ �� ���� �߰��� �� �ִٸ�
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
	std::cout << "������ " << year << " �� " << month << " �� " << day << " �� �Դϴ� " << std::endl;
}

int main() {
	Date day(2011, 3, 1); //�����ڿ� ���� �ʱ�ȭ(�Ͻ��� �ʱ�ȭ) implicit
	//Date day = Date(2011, 3, 1); //(����� �ʱ�ȭ) explicit
	day.show_date();

	day.add_year(10);
	day.show_date();
	return 0;
}