#pragma once


using namespace std;

class Point
{
	friend ostream& operator<< (ostream&, const Point&);
	friend bool operator<(const Point&, const Point&);
private:
	double point_x;
	double point_y;
public:
//����������� � ����������� � ��������.
	// ���������� ������ Point
	~Point();
	// ����������� ������ Time, ������� ������ ���������������� ���� ��������� ����������.
	Point(double, double);
	double O_point;//���������e �� ����� �� ������ ���������.
	// ��������� x
	void set_x(double);
	// ��������� x
	double get_x();
	// ��������� y
	void set_y(double);
	// ��������� y
	double get_y();
};

