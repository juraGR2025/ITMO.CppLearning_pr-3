#pragma once
#include <string>
#include <iostream>

using namespace std;
/*Создайте класс с именем Time, содержащий три поля типа int, предназначенные
для хранения часов, минут и секунд*/
class Time
{
private:
	int hour;
	int minutes;
	int seconds;
public:

	// Деструктор класса Time
	~Time();
	// Конструктор класса Time, который должен инициализировать поля заданными значениями.
	Time(int, int, int);
	// Конструктор класса Time, который должен инициализировать поля нулевыми значениями
	Time();
	// Установка часов
	void set_hours(int);
	// Получение часов
	int get_hours();
	// Установка минут
	void set_minutes(int);
	// Получение минут
	int get_minutes();
	// Установка секунд
	void set_seconds(int);
	// Получение секунд
	int get_seconds();
	//
	void time_out(Time& t);

	void time_sum(Time& t1, Time& t2);

	Time operator+(Time& t2) const;
	/*Требуется реализовать в классе Time (добавить в ранее созданный класс)
перегрузку следующий операций:
• сложение объектов Time,
• вычитание объектов Time,
• сложение объекта Time и переменной вещественного типа,
• сложение переменной вещественного типа и объект Time,
• сравнение двух объектов Time.
Реализуйте возможность преобразования полученных результатов к
корректному виду.
В функции main() создайте требуемые объекты и проверьте работу
перегруженных операций.*/
	Time operator-(Time& t2) const;
	Time operator+=(double f) const;
// • сложение переменной вещественного типа и объектa Time.
	Time operator+(double f) const;
// • сравнение двух объектов Time.
	Time operator<=(Time& t2) const;
};