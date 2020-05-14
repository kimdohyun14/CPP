#include <stdio.h>

void MaxAndMin(int** dMaxPtr, int** dMinPtr, int* arr, int len) {
	int maxIdx = 0, minIdx = 0;
	int i;

	for (i = 1; i < len; i++) {
		if (arr[maxIdx] < arr[i])
			maxIdx = i;
		if (arr[minIdx] > arr[i])
			minIdx = i;
	}

	*dMaxPtr = &arr[maxIdx];
	*dMinPtr = &arr[minIdx];
}

int main() {
	int* maxPtr;
	int* minPtr;
	int arr[5] = { 1,2,3,4,5 };

	MaxAndMin(&maxPtr, &minPtr, arr, sizeof(arr) / sizeof(int));
	printf("max : %d , min : %d \n", *maxPtr, *minPtr);
	return 0;
}