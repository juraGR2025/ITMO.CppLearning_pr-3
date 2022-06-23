// ITMO.CppLearning_pr-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

string privet(string name)
{
	string str = name + ", " + "hello!\n";
	return str;
}
/*В проекте упражнения 1 добавьте(не замените имеющуюся, а именно
	добавьте новую) вторую функцию privet(), но с двумя параметрами.*/
void privet(string name, int k)
{
	cout << name << ", " << "hello! " << "you input " << k << endl;
}
int main()
{
	string name;
	int k;/*В функции main() объявите целочисленную переменную и реализуйте
ввод ее значения:*/
	cout << "Input number:" << endl;
	cin >> k;
	cout << "What is your name?" << endl;
	cin >> name;
	string nameOut = privet(name);
	cout << nameOut << endl;
	privet(name);
	privet(name, k);
	return 0;
}
