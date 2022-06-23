// Cpp_practice_3-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;

long double firBinSearch(double a, int n)
{
    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return R;
}

int main()
{
    system("chcp 1251");
    double ra;//Переменная для действительного числа.
    int k;//переменная для корня k-й степени.
    cout << "Enter the number and degree of the root:" << endl;
    cin.setf(ios::fixed);// Фиксированная форма вывода вещественных чисел.
    cin >> setw(6) >> ra;
    cin >> k ;
    cout.setf(ios::fixed);
    double Res = firBinSearch(ra, k);//Переменная Res получает значение результата функции
    cout << "Корень числа " << ra << " степени " << k << " = " << setw(6) << Res << "\n";

}