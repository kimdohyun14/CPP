#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt;
public: // 불필요하지만 변수와 함수의 구분을 목적으로 삽입하기도 한다.
	SoSimple()
	{
		simObjCnt++;
	}
};

int SoSimple::simObjCnt = 0;

int main()
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;

	// public static 멤버에 접근할 때에는 이렇게 사용하지 말고, 위의 내용처럼 사용하자.
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	return 0;
}