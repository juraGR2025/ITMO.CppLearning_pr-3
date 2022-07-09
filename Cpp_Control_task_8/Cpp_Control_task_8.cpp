// Cpp_Control_task_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "time.h"


using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Time* time00 = new Time();// Используется конструктор для 0-объекта
    int h, m, s;

    cout << "Введите часы, минуты, секунды: " << endl;
    cin >> h; 
    cin >> m; 
    cin >> s;

    
 /*В функции main() следует создать два инициализированных объекта(подумайте,
     должны ли они быть константными) и один неинициализированный объект.Затем
        сложите два инициализированных значения, а результат присвойте третьему
        объекту и выведите его значение на экран.*/   
    Time* time01 = new Time(h, m, s);

    cout << "Введите часы, минуты, секунды: " << endl;
    cin >> h;
    cin >> m;
    cin >> s;

    Time* time02 = new Time(h, m, s);

    Time time03;

    time01->time_out(*time01);
time02->time_out(*time02);
time03.time_sum(*time01, *time02);
time03.time_out(time03);
delete time00;
delete time01;
delete time02;

    return 0;
}