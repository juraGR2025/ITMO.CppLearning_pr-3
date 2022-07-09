#include <iostream>
#include <string>
#include "time.h"


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


