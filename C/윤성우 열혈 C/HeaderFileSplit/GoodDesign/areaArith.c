#pragma once
#include "basicArith.h" //  basicArith�� ���ǵ� �Լ��� ����ϹǷ� ����������Ѵ�.

double TriangleArea(double base, double height) {
	return Div(Mul(base, height), 2);
}

double CircleArea(double rad) {
	return Mul(Mul(rad, rad), PI);
}