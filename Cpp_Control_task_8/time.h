#pragma once
#include <string>
#include <iostream>

using namespace std;
/*�������� ����� � ������ Time, ���������� ��� ���� ���� int, ���������������
��� �������� �����, ����� � ������*/
class Time
{
private:
	int hour;
	int minutes;
	int seconds;
public:

	// ���������� ������ Time
	~Time();
	// ����������� ������ Time, ������� ������ ���������������� ���� ��������� ����������.
	Time(int, int, int);
	// ����������� ������ Time, ������� ������ ���������������� ���� �������� ����������
	Time();
	// ��������� �����
	void set_hours(int);
	// ��������� �����
	int get_hours();
	// ��������� �����
	void set_minutes(int);
	// ��������� �����
	int get_minutes();
	// ��������� ������
	void set_seconds(int);
	// ��������� ������
	int get_seconds();
	//
	void time_out(Time& t);

	void time_sum(Time& t1, Time& t2);

	Time operator+(Time& t2) const;
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
������������� ��������.*/
	Time operator-(Time& t2) const;
	Time operator+=(double f) const;
// � �������� ���������� ������������� ���� � ������a Time.
	Time operator+(double f) const;
// � ��������� ���� �������� Time.
	Time operator<=(Time& t2) const;
};