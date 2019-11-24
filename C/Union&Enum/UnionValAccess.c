#include <stdio.h>

// 공용체의 멤버들이 메모리 공간을 공유하고 있다는 것을 알 수 있다.

typedef union ubox {
	int mem1;
	int mem2;
	double mem3;
}UBox;

int main() {
	UBox ubx; // 8바이트 메모리 할당 (멤버 중 가장 큰 멤버 변수만 할당되어서 공유)

	ubx.mem1 = 20; // 상위 4바이트의 메모리 공간에 20을 저장
	printf("%d \n", ubx.mem2); // 상위 4바이트의 메모리 공간에 참조

	ubx.mem3 = 7.15; // 12행에 저장했던 값을 덮어쓴다. (공유하기 때문에)
	printf("%d \n", ubx.mem1);  // 덮어써버리게 되었으니 상위 4바이트를 읽게되면 알 수 없는 값이 출력된다.
	printf("%d \n", ubx.mem2);
	printf("%g \n", ubx.mem3);
	return 0;
}