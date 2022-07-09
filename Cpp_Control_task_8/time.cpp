#include <iostream>
#include <string>
#include "time.h"


using namespace std;

// ƒеструктор Time
Time::~Time()
{
	cout << "–аботает деструктор. ";
}

/*2. ¬ файле time.cpp определ€ем сам конструктор.
ќдин из конструкторов класса должен инициализировать пол€ нулевыми
значени€ми, а другой конструктор Ч заданным набором значений.*/
Time::Time(int hours, int minutes, int seconds)
{
	
	/*¬ конструктор с параметрами добавьте реализацию приведени€ больших
неправильных значений параметров к правильным значени€м, например, если
клиент захочет создать врем€ с параметром минут равным 70, то конструктор
должен преобразовать это значение к правильному виду: количество часов и
минут.*/

		int sumseconds = 0;
		sumseconds = minutes * 60;
		sumseconds = sumseconds + seconds + hours * 60 * 60;

		if (sumseconds >= 3600) {
			hours = sumseconds / 60 / 60;
			minutes = (sumseconds - hours * 60 * 60) / 60;
			seconds = sumseconds - hours * 60 * 60 - minutes * 60;
			if (hours > 23) {
				hours = hours % 24;
			}

		}
		else if (sumseconds >= 60 && sumseconds < 3600) {
			hours = 0;
			minutes = sumseconds / 60;
			seconds = sumseconds - minutes * 60;
		}
		else {
			hours = 0;
			minutes = 0;
			seconds = sumseconds;
		}

		Time::set_hours(hours);
		Time::set_minutes(minutes);
		Time::set_seconds(seconds);
}
/*2. ¬ файле time.cpp определ€ем конструктор, который инициализирует пол€ 0 значени€ми*/
Time::Time()
{
	Time::set_hours(0);
	Time::set_minutes(0);
	Time::set_seconds(0);
}

// ”становка часов
void Time::set_hours(int my_hours)
{
	Time::hour = my_hours;
}
// ѕолучение часов
int Time::get_hours()
{
	return Time::hour;
}
void Time::set_minutes(int my_minutes)
{
	Time::minutes = my_minutes;
}
// ѕолучение минут
int Time::get_minutes()
{
	return Time::minutes;
}
void Time::set_seconds(int my_seconds)
{
	Time::seconds = my_seconds;
}
// ѕолучение секунд
int Time::get_seconds()
{
	return Time::seconds;
}
/*—оздайте метод класса, который будет выводить значени€ полей на экран в
формате 11:59:59, и метод, складывающий значени€ двух объектов типа Time,
передаваемых в качестве аргументов.
√де это возможно и оправдано, сделайте методы константными.*/
// ‘ункци€, вывод€ща€ значени€ пол
void Time::time_out(Time &t)
{
	cout << "¬веденное врем€: " << endl;
	string str = to_string(t.get_hours()) + " : " + to_string(t.get_minutes()) + " : " + to_string(t.get_seconds());
	cout << str << endl;
}
void  Time::time_sum(Time &t1, Time &t2) 
{
	int h = t1.get_hours() + t2.get_hours();
	int m = t1.get_minutes() + t2.get_minutes();
	int s = t1.get_seconds() + t2.get_seconds();

	Time *t3 = new Time(h, m, s);
	cout << "«авершение ожидаетс€ в  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
}


