// ITMO.CppLearning_pr-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void privet(string);

int main()
{
	setlocale(LC_ALL, "Russian");
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);
	return 0;
}

void privet(string name)
{
	cout << name << ", " << "hello!" << endl;
}