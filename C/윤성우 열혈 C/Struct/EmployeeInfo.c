#include <stdio.h>
#include <string.h>

struct employee {
	char employeeName[20];
	char employeeSSN[20];
	int salary;
};

int main() {
	struct employee emp1;

	printf("������ �̸� : "); scanf("%s", emp1.employeeName);
	printf("�ֹε�Ϲ�ȣ : "); scanf("%s", emp1.employeeSSN);
	printf("�޿����� : "); scanf("%d", &emp1.salary);

	printf("\n *** ������ infomation *** \n");
	printf("������ �̸��� %s \n", emp1.employeeName);
	printf("�ֹε�Ϲ�ȣ�� %s \n", emp1.employeeSSN);
	printf("�������� �޿��� %d �Դϴ�. \n", emp1.salary);
	return 0;
}