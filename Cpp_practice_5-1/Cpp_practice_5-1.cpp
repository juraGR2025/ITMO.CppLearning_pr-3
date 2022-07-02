// Cpp_practice_5-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
using namespace std;

/*Контрольные задания
Задание 1. Передача массива в функцию
Реализуйте созданный вами функционал в упражнениях 1 и 2 в виде
соответствующих функций, которые будут принимать массив и возвращать
требуемые результаты.
Функция должна принимать два параметра: целочисленное значение – размер
массива и сам массив.*/

string sumFunc(int N, int mas[]) {
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        s += mas[i];
    }
    double ps = (double(s) / N);

    string str1 = "Значение суммы: " + to_string(s) + '\t';
    string str2 = "Среднее значение элементов массива: " + to_string(ps) + '\t';
    string str = str1 + str2;
    return str;
}
string averageFunc(int N, int mas[]) {//Функция для вычисления сумм элементов
    int s = 0;
    int sp = 0;
    int sum_odd_indexes = 0;//с нечетными индексами
    int sum_even_indexes = 0;//с четными индексами.

    for (int i = 0; i < N; i++)
    {
        if (mas[i] < 0) s += mas[i];
        if (mas[i] > 0) sp += mas[i];
        if (i % 2 != 0) sum_odd_indexes += mas[i];
        if (i % 2 == 0) sum_even_indexes += mas[i];
    }
    string str1 = "Значение суммы отрицательных элементов: " + to_string(s) + '\n';
    string str2 = "Значение суммы положительных элементов: " + to_string(sp) + '\n';
    string str3 = "Значение суммы элементов с нечетными индексами: " + to_string(sum_odd_indexes) + '\n';
    string str4 = "Значение суммы элементов с четными индексами: " + to_string(sum_even_indexes) + '\n';
    string str = str1 + str2 + str3 + str4;
    return str;
}
string maxFunc(int N, int mas[]) {//Функция для поиска элементов
    int MinArr = mas[0];
    int indexMinArr = 0;
    int MaxArr = mas[N];
    int indexMaxArr = 0;
    for (int i = 0; i < N; i++)
    {
        if (MinArr > mas[i]) {
            MinArr = mas[i];
            indexMinArr = i;
        }
        if (MaxArr < mas[i]) {
            MaxArr = mas[i];
            indexMaxArr = i;
        }
    }
    string str1 = "Индекс максимального элемента: " + to_string(indexMaxArr) + '\n';
    string str2 = "Индех минимального элемента: " + to_string(indexMinArr) + '\n';
    int s = 1;
    for (int i = indexMinArr + 1; i < indexMaxArr; i++) {
        s = s * mas[i];
    }
    string str3 = "Произведение элементов: " + s + '\n';
    string str = str1 + str2 + str3;
    return str;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int n = 10;// Объявляется константа, чтобы задать размер массива. 
    int mas[n];// Объявляется массив целых чисел размером n.
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }

    string rezString = sumFunc(n, mas);//Функция для поиска суммы значений массива и среднего значения элементов массива
    cout << rezString << endl;

    /*
    Добавьте в функции main() новые возможности обработки данных
массива:
a. расчет суммы отрицательных элементов,
b. расчет суммы положительных элементов,
c. расчет суммы элементов с нечетными индексами,
d. расчет суммы элементов с четными индексами.*/
    string rezString2 = averageFunc(n, mas);//Функция суммы значений элементов массива
    cout << rezString2 << endl;
  /*a. найти максимальный и минимальный элементы массива и вывести их индексы,
    b. рассчитать произведение элементов массива, расположенных между максимальным 
    и минимальным элементами*/
    string rezString3 = maxFunc(n, mas);//Функция суммы значений элементов массива
    cout << rezString3 << endl;
}
