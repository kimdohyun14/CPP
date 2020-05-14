#ifndef __STDIV2_H__
#define __STDIV2_H__

// 조건부 컴파일을 활용하면 중복삽입의 문제를 해결할 수 있다.
// 헤더파일은 #ifndef~#endif를 이용해서 중복삽입의 문제를 미연에 방지하는 것이 좋다.
typedef struct div {
	int quotient;  // 몫
	int remainder; // 나머지
}Div;

#endif