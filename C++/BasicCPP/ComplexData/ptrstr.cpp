#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char animal[20] = "bear";
	const char* bird = "wren"; // 큰따옴표로 둘러싸인 문자열은 그 문자열의 첫 번째 문자의 주소를 나타낸다.
	char* ps;

	cout << animal << " and " << bird << endl;
	// cout << ps << endl; 먹통이 될 수 있음.

	cout << "동물의 종류를 입력하세요: ";
	cin >> animal; // 입력이 20문자 이내여야 한다.
	// cin >> ps; 절대로 해서는 안되는 실수
	// ps가 대입된 공간을 지시하고 있지 않기 때문이다.

	ps = animal; // 주소 복사, 같은 메모리 위치와 같은 문자열을 지시하게 된다.
	cout << ps << "s!\n";
	cout << "strcpy() 사용전:\n";
	// 문자열의 주소를 알고 싶다면 포인터를 다른 포인터형으로 변환해야 한다.
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1]; // 새 메모리를 대입한다.
	strcpy(ps, animal); // 서로 별개인 두 벌의 "fox"를 얻게 된다.
	cout << "strcpy() 사용후:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;
	return 0;
}