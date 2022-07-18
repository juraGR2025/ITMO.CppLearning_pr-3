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
//Конструктор с параметрами и функцией.
	// Деструктор класса Point
	~Point();
	// Конструктор класса Time, который должен инициализировать поля заданными значениями.
	Point(double, double);
	double O_point;//Расстояниe от точки до центра координат.
	// Установка x
	void set_x(double);
	// Получение x
	double get_x();
	// Установка y
	void set_y(double);
	// Получение y
	double get_y();
};

