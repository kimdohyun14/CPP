#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y) { }
	void ShowPosition()const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template<typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) :mdata(data) { }
	void ShowDataInfo()
	{
		cout << "Data: " << mdata << endl;
	}
};

template<>
class SimpleDataWrapper<const char*>
{
private:
	const char* mdata;
public:
	SimpleDataWrapper(const char* data) : mdata(data) {}
	void ShowDataInfo()
	{
		cout << "String: " << mdata << endl;
		cout << "Length: " << strlen(mdata) << endl;
	}
};

template<>
class SimpleDataWrapper<Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) :mdata(x, y) { }
	void ShowDataInfo()
	{
		mdata.ShowPosition();
	}
};

int main()
{
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo();
	SimpleDataWrapper<const char*> swrap("Class Template Specialization");
	swrap.ShowDataInfo();
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}