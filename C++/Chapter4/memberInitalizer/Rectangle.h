#pragma once
#include "Point.h"

class Rectangle {
private:
	Point upLeft;
	Point lowRight;

public:
	//bool InitMembers(const Point &ul, const Point &lr);
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
	void ShowRecInfo() const;
};
