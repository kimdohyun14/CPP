extern int num; // int형 변수 num이 외부에 선언되어 있다. (extern 키워드 생략가능)

void Increment() {
	num++;
}

int GetNum() {
	return num;
}