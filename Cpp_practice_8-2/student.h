/* student.h */
#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
#include "IdCard.h"
using namespace std;
class Student
{
public:
	//1. Добавьте прототипы деструктора и метода save()в файл student.h:
	// Запись данных о студенте в файл
	void save();
	// Деструктор класса Student
	~Student();
	/*В классе Student (файл Student.h) объявите указатель iCard на объект
типа IdCard:*/
	IdCard iCard;
	/*и методы для управления доступом к этому полю (записи и получения значения):*/
	void setIdCard(IdCard c);
	IdCard getIdCard();

	// Конструктор класса Student
	Student(string, string, IdCard);

	// Установка имени студента
	void set_name(string);
	// Получение имени студента
	string get_name();
	// Установка фамилии студента
	void set_last_name(string);
	// Получение фамилии студента
	string get_last_name();
	// Установка промежуточных оценок
	void set_scores(int[]);
	// Установка среднего балла
	void set_average_score(double);
	// Получение среднего балла
	double get_average_score();
private:
	// Промежуточные оценки
	int scores[5];
	// Средний балл
	double average_score;
	// Имя
	string name;
	// Фамилия
	string last_name;

};
