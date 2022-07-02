// Cpp_practice_5-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
using namespace std;
string sortFunc(int N, int mas[]) {
    
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
    /*Указание. Для создания динамического массива можно использовать следующий
код, например: int* myArray = new int[n];
В данном примере myArray является указателем на массив из n элементов.
Не забудьте после использования массива освободить динамическую память.*/
    int* myArray = new int[N];
    for (int i = 0; i < N; i++)
    {
        cout << "myArray[" << i << "]=";
        cin >> myArray[i];
    }
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (mas[j] < mas[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = mas[i];
            mas[i] = mas[min];
            mas[min] = buf;
        }
    }
    /*Реализуйте вывод отсортированного массива на экран.Для этого вместо
  стандартного варианта цикла for можно применить цикл с перебором
   массива(foreach) :*/
    string str = " ";

    for (int i = 0; i < N; i++)
    {
        str += to_string(mas[i]) + '\t';
    }
    return str;
    delete[] myArray;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    string rezStr = sortFunc(N, a);
    cout << rezStr;
}
