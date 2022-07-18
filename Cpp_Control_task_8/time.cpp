#include <iostream>
#include <string>
#include "time.h"
#include "math.h"


using namespace std;

// ���������� Time
Time::~Time()
{
	cout << "�������� ����������. ";
}

/*2. � ����� time.cpp ���������� ��� �����������.
���� �� ������������� ������ ������ ���������������� ���� ��������
����������, � ������ ����������� � �������� ������� ��������.*/
Time::Time(int hours, int minutes, int seconds)
{
	
	/*� ����������� � ����������� �������� ���������� ���������� �������
������������ �������� ���������� � ���������� ���������, ��������, ����
������ ������� ������� ����� � ���������� ����� ������ 70, �� �����������
������ ������������� ��� �������� � ����������� ����: ���������� ����� �
�����.*/

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

/*2. � ����� time.cpp ���������� �����������, ������� �������������� ���� 0 ����������*/
Time::Time()
{
	Time::set_hours(0);
	Time::set_minutes(0);
	Time::set_seconds(0);
}

// ��������� �����
void Time::set_hours(int my_hours)
{
	Time::hour = my_hours;
}
// ��������� �����
int Time::get_hours()
{
	return Time::hour;
}
void Time::set_minutes(int my_minutes)
{
	Time::minutes = my_minutes;
}
// ��������� �����
int Time::get_minutes()
{
	return Time::minutes;
}
void Time::set_seconds(int my_seconds)
{
	Time::seconds = my_seconds;
}
// ��������� ������
int Time::get_seconds()
{
	return Time::seconds;
}
/*�������� ����� ������, ������� ����� �������� �������� ����� �� ����� �
������� 11:59:59, � �����, ������������ �������� ���� �������� ���� Time,
������������ � �������� ����������.
��� ��� �������� � ���������, �������� ������ ������������.*/
// �������, ��������� �������� ���
void Time::time_out(Time &t)
{
	cout << "��������� �����: " << endl;
	string str = to_string(t.get_hours()) + " : " + to_string(t.get_minutes()) + " : " + to_string(t.get_seconds());
	cout << str << endl;
}
void  Time::time_sum(Time &t1, Time &t2) 
{
	int h = t1.get_hours() + t2.get_hours();
	int m = t1.get_minutes() + t2.get_minutes();
	int s = t1.get_seconds() + t2.get_seconds();

	Time *t3 = new Time(h, m, s);
	cout << "���������� ��������� �  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
}

/*��������� ����������� � ������ Time (�������� � ����� ��������� �����)
���������� ��������� ��������:
� �������� �������� Time,
� ��������� �������� Time,
� �������� ������� Time � ���������� ������������� ����,
� �������� ���������� ������������� ���� � ������ Time,
� ��������� ���� �������� Time.
���������� ����������� �������������� ���������� ����������� �
����������� ����.
� ������� main() �������� ��������� ������� � ��������� ������
������������� ��������.
*************************************************
���������� ����������� ������� �������� �������:*/
Time Time::operator+ (Time& t2) const
{
	int h = hour + t2.get_hours();
	int m = minutes + t2.get_minutes();
	int s = seconds + t2.get_seconds();

	Time* t3 = new Time(h, m, s);// ����������� Time(int hours, int minutes, int seconds) ��� ����������� ����� � ����������� ����...
	cout << "������������� �������� +  " << endl;
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

		Time* t3 = new Time(h, m, s);// ����������� Time(int hours, int minutes, int seconds) ��� ����������� ����� � ����������� ����...
		cout << "������������� �������� -  " << endl;
		string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
		cout << str << endl;
		return Time(h, m, s);
	}
	else cout << "����� �����!" << endl;
}

Time Time::operator+=(double f) const
{
	int h = hour + (int)f;// ��������� �������� ����� � ����� ����� ������������� �����
	int m = minutes + (int)(abs(f - (int)f)*60);// ������� �������� ����� ����� f
	int s = seconds;

	Time* t3 = new Time(h, m, s);// ����������� Time(int hours, int minutes, int seconds) ��� ����������� ����� � ����������� ����...
	cout << "������������� �������� +=  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
	return Time(h, m, s);
}
// � �������� ���������� ������������� ���� � ������a Time.
Time Time::operator+(double f) const
{
	int h = hour + (int)f;// ��������� �������� ����� � ����� ����� ������������� �����
	int m = minutes + (int)(abs(f - (int)f) * 60);// ������� �������� ����� ����� f
	int s = seconds;

	Time* t3 = new Time(h, m, s);// ����������� Time(int hours, int minutes, int seconds) ��� ����������� ����� � ����������� ����...
	cout << "������������� �������� + 2 ���  " << endl;
	string str = to_string(t3->get_hours()) + " : " + to_string(t3->get_minutes()) + " : " + to_string(t3->get_seconds());
	cout << str << endl;
	return Time(h, m, s);
}

Time Time::operator<=(Time& t2) const
{
	if ((hour * 60 * 60 + minutes * 60 + seconds) <= (t2.get_hours() * 60 * 60 + t2.get_minutes() * 60 + t2.get_seconds()))
	{
		cout << "������������� �������� <=  " << endl;
		string str = "�������� ������� " + to_string(t2.get_hours()) + " : " + to_string(t2.get_minutes()) + " : " + to_string(t2.get_seconds()) + 
			" ������ ��� " + to_string(hour) + " : " + to_string(minutes) + " : " + to_string(seconds);
		cout << str << endl;
		return Time();
	}
	else cout << "�������� ������� " + to_string(t2.get_hours()) + " : " + to_string(t2.get_minutes()) + " : " + to_string(t2.get_seconds()) +
		" ������ ��� " + to_string(hour) + " : " + to_string(minutes) + " : " + to_string(seconds) << endl;
}

