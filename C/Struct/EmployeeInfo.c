#include <stdio.h>
#include <string.h>

struct employee {
	char employeeName[20];
	char employeeSSN[20];
	int salary;
};

int main() {
	struct employee emp1;

	printf("종업원 이름 : "); scanf("%s", emp1.employeeName);
	printf("주민등록번호 : "); scanf("%s", emp1.employeeSSN);
	printf("급여정보 : "); scanf("%d", &emp1.salary);

	printf("\n *** 종업원 infomation *** \n");
	printf("종업원 이름은 %s \n", emp1.employeeName);
	printf("주민등록번호는 %s \n", emp1.employeeSSN);
	printf("종업원의 급여는 %d 입니다. \n", emp1.salary);
	return 0;
}