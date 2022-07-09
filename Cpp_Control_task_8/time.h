#pragma once
#include <string>
#include <iostream>

using namespace std;
/*—оздайте класс с именем Time, содержащий три пол€ типа int, предназначенные
дл€ хранени€ часов, минут и секунд*/
class Time
{
private:
	int hour;
	int minutes;
	int seconds;
public:

	// ƒеструктор класса Time
	~Time();
	//  онструктор класса Time, который должен инициализировать пол€ заданными значени€ми.
	Time(int, int, int);
	//  онструктор класса Time, который должен инициализировать пол€ нулевыми значени€ми
	Time();
	// ”становка часов
	void set_hours(int);
	// ѕолучение часов
	int get_hours();
	// ”становка минут
	void set_minutes(int);
	// ѕолучение минут
	int get_minutes();
	// ”становка секунд
	void set_seconds(int);
	// ѕолучение секунд
	int get_seconds();
	//
	void time_out(Time& t);

	void time_sum(Time& t1, Time& t2);

};