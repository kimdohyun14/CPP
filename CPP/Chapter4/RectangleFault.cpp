#include <iostream>
using namespace std;

class Point {
public:
	int x; //x좌표의 범위는 0이상 100이하
	int y; //y좌표의 범위는 0이상 100이하
};

class Rectangle {
public:
	Point upLeft;
	Point lowRight;
public:
	void showRecInfo() {
		cout << "좌 상단: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 상단: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;
	}
};

int main() {
	Point pos1 = { -2,4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2,pos1 };
	rec.showRecInfo();
	return 0;
}