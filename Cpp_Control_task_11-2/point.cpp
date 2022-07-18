#include <iostream>
#include <string>
#include "point.h"
#include "math.h"

using namespace std;

// Деструктор Point
Point::~Point()
{
	cout << "Работает деструктор. " << endl;
}
Point::Point(double x, double y) {
	Point::set_x(x);
	Point::set_y(y);
	O_point = sqrt(x * x + y * y);
}

void Point::set_x(double my_x)
{
	Point::point_x = my_x;
}

double Point::get_x()
{
	return Point::point_x;
}

void Point::set_y(double my_y)
{
	Point::point_y = my_y;
}

double Point::get_y()
{
	return Point::point_y;
}
ostream& operator<< (ostream& strm, const Point& point)
{
	strm << "[" << point.point_x << ", " << point.point_y << "]" << endl;
	return strm;
}

bool operator<(const Point& point1, const Point& point2) {
	if (point1.O_point < point2.O_point) return true;
	return false;
}
