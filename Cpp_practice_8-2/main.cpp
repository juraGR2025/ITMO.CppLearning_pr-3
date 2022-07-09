#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "IdCard.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string name;
	string last_name;
	// Ввод имени с клавиатуры
	cout << "Name: ";
	getline(cin, name);
	// Ввод фамилии
	cout << "Last name: ";
	getline(cin, last_name);
	/*В функции main() создайте объект класса IdCard с передачей двух
значений для инициализации объекта:*/
	IdCard idc(123, "Базовый");
	idc.setNumber(123);
	idc.setCategory("Базовый");
	// Передача параметров конструктору
	Student* student02 = new Student(name, last_name, idc);//==========?
	// Оценки
	int scores[5];
	// Сумма всех оценок
	int sum = 0;
	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}
	// Сохраняем промежуточные оценки в объект класса Student
	student02->set_scores(scores);
	// Считаем средний балл
	double average_score = sum / 5.0;
	// Сохраняем средний балл в объект класса Student
	student02->set_average_score(average_score);
	// Выводим данные по студенту
	cout << "Average ball for " << student02->get_name() << " "
		<< student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;

	
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;


	// Удаление объекта student из памяти
	delete student02;
	return 0;

}