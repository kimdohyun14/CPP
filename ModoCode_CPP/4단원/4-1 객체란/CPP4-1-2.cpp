#include <iostream>

class Date {
	int year;
	int month;
	int day;

public:
	void set_date(int _year, int _month, int _day) {
		year = 0;
		month = 0;
		day = 0;
		add_year(_year);
		add_month(_month);
		add_day(_day);
	}

	void add_day(int inc) {
		//28�� : 2��
		//31�� : 1, 3, 5, 7, 8, 10, 12��
		//30�� : 4, 6, 9, 11��
		//������ ����

		int increase_month = 0; //������ �� ��

		switch (month) {
		case 2 :
			if (day + inc > 28) {
				day += inc;
				increase_month = day / 28;
				day %= 28;
				
				add_month(increase_month);
			}
			else {
				day += inc;
			}
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day + inc > 31) {
				day += inc;
				increase_month = day / 31;
				day %= 31;

				add_month(increase_month);
			}
			else {
				day += inc;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (day + inc > 30) {
				day += inc;
				increase_month = day / 30;
				day %= 30;

				add_month(increase_month);
			}
			break;
		}
	}

	void add_month(int inc) {
		//12���� �Ѿ�� 1��, 1���� �ȴ�.

		int increase_year = 0; //������ �⵵ ��

		if (month + inc > 12) {
			month += inc;
			increase_year = month / 12;
			month %= 12;
			
			add_year(increase_year);
		}
		else {
			month += inc;
		}
	}

	void add_year(int inc) {
		//�⵵�� �����ص� ������ ����.
		year += inc;
	}

	void get_date() {
		std::cout << year << "�� " << month << "�� " << day << "��" << std::endl;
	}
};

int main() {
	Date date1;

	date1.set_date(2019, 2, 28);
	date1.add_day(1);
	date1.get_date();

	Date date2;

	date2.set_date(2019, 12, 31);
	date2.add_day(1);
	date2.get_date();
	return 0;
}