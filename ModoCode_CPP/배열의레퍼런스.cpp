#include <iostream>

//배열의 레퍼런스
int main() {
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}

//배열의 레퍼런스는 잘 사용되지 않는다.
//배열의 크기를 명확히 명시해 주어야하기 때문에
//배열을 가리킬 필요가 있는 경우는 레퍼런스 보다는 포인터를 사용하는 것을 권장