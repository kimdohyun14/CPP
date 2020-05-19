#include <iostream>
using namespace std;

// unique_ptr 메모리 해제 이후에 객체에 다시 접근하게 되면?
int main()
{
	int* arr = new int[10]; // 동적 할당
	unique_ptr<int> p1(arr);
	for (int i = 0; i < 10; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << endl;

	p1.reset(); // 메모리 해제

	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // 쓰레기 값 출력
	cout << endl;
	return 0;
}