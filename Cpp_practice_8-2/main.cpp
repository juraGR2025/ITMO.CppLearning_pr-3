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
	// ���� ����� � ����������
	cout << "Name: ";
	getline(cin, name);
	// ���� �������
	cout << "Last name: ";
	getline(cin, last_name);
	/*� ������� main() �������� ������ ������ IdCard � ��������� ����
�������� ��� ������������� �������:*/
	IdCard idc(123, "�������");
	idc.setNumber(123);
	idc.setCategory("�������");
	// �������� ���������� ������������
	Student* student02 = new Student(name, last_name, idc);//==========?
	// ������
	int scores[5];
	// ����� ���� ������
	int sum = 0;
	// ���� ������������� ������
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// ������������
		sum += scores[i];
	}
	// ��������� ������������� ������ � ������ ������ Student
	student02->set_scores(scores);
	// ������� ������� ����
	double average_score = sum / 5.0;
	// ��������� ������� ���� � ������ ������ Student
	student02->set_average_score(average_score);
	// ������� ������ �� ��������
	cout << "Average ball for " << student02->get_name() << " "
		<< student02->get_last_name() << " is "
		<< student02->get_average_score() << endl;

	
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;


	// �������� ������� student �� ������
	delete student02;
	return 0;

}