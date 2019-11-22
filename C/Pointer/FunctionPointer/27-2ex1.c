#include <stdio.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int ary[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (ary[j] % 2 != 0 && ary[j + 1] % 2 != 0) {
				if (ary[j] > ary[j + 1]) {
					swap(&ary[j], &ary[j + 1]);
				}
			}
			else if (ary[j] % 2 == 0 && ary[j + 1] % 2 == 0) {
				if (ary[j] > ary[j + 1]) {
					swap(&ary[j], &ary[j + 1]);
				}
			}
			else if (ary[j] % 2 == 0 && ary[j + 1] % 2 != 0) {
				swap(&ary[j], &ary[j + 1]);
			}
		}
	}
}

int main()
{
	int arr[] = { 3,2,1,4,6,8,7,5,3,4,5 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}