#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator+=(const Point& pos)
	{
		this->xpos += pos.xpos;
		this->ypos += pos.ypos;
		return *this;
	}

	Point& operator-=(const Point& pos)
	{
		this->xpos -= pos.xpos;
		this->ypos -= pos.ypos;
		return *this;
	}

	friend Point operator-(const Point& pos1, const Point& pos2);
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
	return (pos1.xpos == pos1.ypos) ? ((pos1.ypos == pos2.ypos) ? true : false) : false;
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}

int main()
{
	Point pos1(10, 20);
	Point pos2(5, 15);
	Point pos3 = pos1 - pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	cout << endl;

	pos1 += pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();

	pos1 -= pos2;
	pos1.ShowPosition();
	pos2.ShowPosition();

	cout << (pos1 == pos2) << endl;
	Point pos4(5, 5);
	Point pos5(5, 5);
	cout << (pos4 == pos5) << endl;
	return 0;
}