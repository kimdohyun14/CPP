// ����Լ�
// recursion
// ���丮��
// 5! = 5*4*3*2*1 = 120
// n! = n * (n-1)!
#include <cstdio>
int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}
int main() {
	printf("%d\n", factorial(5));
	return 0;
}