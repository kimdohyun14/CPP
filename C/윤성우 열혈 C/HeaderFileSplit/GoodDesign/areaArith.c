#pragma once
#include "basicArith.h" //  basicArith에 정의된 함수를 사용하므로 선언해줘야한다.

double TriangleArea(double base, double height) {
	return Div(Mul(base, height), 2);
}

double CircleArea(double rad) {
	return Mul(Mul(rad, rad), PI);
}