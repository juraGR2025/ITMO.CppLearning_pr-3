#include <iostream>
#include <string>
#include "time.h"
#include "math.h"


using namespace std;

// Деструктор Time
Time::~Time()
{
	cout << "Работает деструктор. ";
}

/*2. В файле time.cpp определяем сам конструктор.
Один из конструкторов класса должен инициализировать поля нулевыми
значениями, а другой конструктор — заданным набором значений.*/
Time::Time(int hours, int minutes, int seconds)
{
	
	/*В конструктор с параметрами добавьте реализацию приведения больших
неправильных значений параметров к правильным значениям, например, если
клиент захочет создать время с параметром минут равным 70, то конструктор
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

/*2. В файле time.cpp определяем конструктор, который инициализирует поля 0 значениями*/
Time::Time()
{
	Time::set_hours(0);
	Time::set_minutes(0);
	Time::set_seconds(0);
}

// Установка часов
void Time::set_hours(int my_hours)
{
	Time::hour = my_hours;
}
// Получение часов
int Time::get_hours()
{
	return Time::hour;
}
void Time::set_minutes(int my_minutes)
{
	Time::minutes = my_minutes;
}
// Получение минут
int Time::get_minutes()
{
	return Time::minutes;
}
void Time::set_seconds(int my_seconds)
{
	Time::seconds = my_seconds;
}
// Получение секунд
int Time::get_seconds()
{
	return Time::seconds;
}
/*Создайте метод класса, который будет выводить значения полей на экран в
формате 11:59:59, и метод, складывающий значения двух объектов типа Time,
передаваемых в качестве аргументов.
Где это возможно и оправдано, сделайте методы константными.*/
// Функция, выводящая значения пол
void Time::time_out(Time &t)
{
	cout << "Введенное время: " << endl;
	string str = to_string(t.get_hours()) + " : " + to_string(t.get_minutes()) + " : " + to_string(t.get_seconds());
	cout << str << endl;
}
void  Time::time_sum(Time &t1, Time &t2) 
{
	int h = t1.get_hours() + t2.get_hours();
	int m = t1.get_minutes() + t2.get_minutes();
	int s = t1.get_seconds() + t2.get_seconds();

	Time *t3 = new Time(h, m, s);
	cout << "Завершение ожидается в  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
}

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
перегруженных операций.
*************************************************
Определяем операторную функцию сложения времени:*/
Time Time::operator+ (Time& t2) const
{
	int h = hour + t2.get_hours();
	int m = minutes + t2.get_minutes();
	int s = seconds + t2.get_seconds();

	Time* t3 = new Time(h, m, s);// Конструктор Time(int hours, int minutes, int seconds) сам преобразует время к правильному типу...
	cout << "Перегруженный оператор +  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;

	return Time(h, m, s);
}

Time Time::operator-(Time& t2) const
{
	if ((hour * 60 * 60 + minutes * 60 + seconds) >= (t2.get_hours() * 60 * 60 + t2.get_minutes() * 60 + t2.get_seconds()))
	{
		int h = hour - t2.get_hours();
		int m = minutes - t2.get_minutes();
		int s = seconds - t2.get_seconds();

		Time* t3 = new Time(h, m, s);// Конструктор Time(int hours, int minutes, int seconds) сам преобразует время к правильному типу...
		cout << "Перегруженный оператор -  " << endl;
		string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
		cout << str << endl;
		return Time(h, m, s);
	}
	else cout << "Время вышло!" << endl;
}

Time Time::operator+=(double f) const
{
	int h = hour + (int)f;// Складываю значение часов и целой части вещественного числа
	int m = minutes + (int)(abs(f - (int)f)*60);// Получаю значение минут числа f
	int s = seconds;

	Time* t3 = new Time(h, m, s);// Конструктор Time(int hours, int minutes, int seconds) сам преобразует время к правильному типу...
	cout << "Перегруженный оператор +=  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
	return Time(h, m, s);
}
// • сложение переменной вещественного типа и объектa Time.
Time Time::operator+(double f) const
{
	int h = hour + (int)f;// Складываю значение часов и целой части вещественного числа
	int m = minutes + (int)(abs(f - (int)f) * 60);// Получаю значение минут числа f
	int s = seconds;

	Time* t3 = new Time(h, m, s);// Конструктор Time(int hours, int minutes, int seconds) сам преобразует время к правильному типу...
	cout << "Перегруженный оператор + 2 раз  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
	return Time(h, m, s);
}

Time Time::operator<=(Time& t2) const
{
	if ((hour * 60 * 60 + minutes * 60 + seconds) <= (t2.get_hours() * 60 * 60 + t2.get_minutes() * 60 + t2.get_seconds()))
	{
		cout << "Перегруженный оператор <=  " << endl;
		string str = "Значение времени " + to_string(t2.get_hours()) + " : " + to_string(t2.get_minutes()) + " : " + to_string(t2.get_seconds()) + 
			" больше чем " + to_string(hour) + " : " + to_string(minutes) + " : " + to_string(seconds);
		cout << str << endl;
		return Time();
	}
	else cout << "Значение времени " + to_string(t2.get_hours()) + " : " + to_string(t2.get_minutes()) + " : " + to_string(t2.get_seconds()) +
		" меньше чем " + to_string(hour) + " : " + to_string(minutes) + " : " + to_string(seconds) << endl;
}

