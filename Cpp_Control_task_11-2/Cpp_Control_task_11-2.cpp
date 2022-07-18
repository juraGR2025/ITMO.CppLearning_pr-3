// Cpp_Control_task_11-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include "point.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для
    // класса Point
    for (auto& point : v)
        std::cout << point << '\n'; // требуется перегрузка оператора << для
        // класса Point
    return 0;
}

