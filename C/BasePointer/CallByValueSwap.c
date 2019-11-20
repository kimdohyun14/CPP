#include <stdio.h>

// Call-by-value 형태
void Swap(int n1, int n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}


// 단순히 매개변수 사이에서만의 값의 변화만 일어났기 때문에 결과도 같다.
int main() {
	int num1 = 10, num2 = 20;
	printf("변경되기 전 num1 : %d, num2 : %d \n", num1, num2);
	Swap(num1, num2);
	printf("변경된 후 num1 : %d, num2 : %d \n", num1, num2);
	return 0;
}