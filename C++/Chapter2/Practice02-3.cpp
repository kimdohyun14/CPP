#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main() {
	Point * p1 = new Point;
	Point * p2 = new Point;
	p1->xpos = 1; p1->ypos = 1;
	p2->xpos = 2; p2->ypos = 2;
	Point &pref = PntAdder(*p1, *p2);
	cout << pref.xpos << ' ' << pref.ypos << endl;
	delete p1;
	delete p2;
	delete &pref;
	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2) {
	Point * sum = new Point;
	sum->xpos = p1.xpos + p2.xpos;
	sum->ypos = p1.ypos + p2.ypos;
	return *sum;
}