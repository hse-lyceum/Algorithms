#include <iomanip>
#include <iostream>

/*
 * Задача: найти методом двоичного поиска квадратный корень из числа x и вывести его целую часть
 *
 * Метод двоичного поиска: делим промежуток от 0 до х пополам и считаем получившееся число приближенным
 * значением квадратного корня из х. Если модуль разницы между квадратом найденного значения корня из х и самим
 * числом х меньше заданной точности epsilon, продолжаем искать до тех пор, пока квадратный корень не будет
 * найден с необходимой точностью
 *
 * В случае, когда число x является точным квадратом, возникают проблемы, связанные с приближённым вычислением корня
 *
 * LeetCode: https://leetcode.com/problems/sqrtx/description/
 */

using std::cin;
using std::cout;
using std::endl;


unsigned long long int isSquare(const unsigned long long int x) {
    for (unsigned long long int i = 0; i * i <= x; i++) {
        if (i * i == x) {
            return i;
        }
    }
    return 0;
}

double binarySearchSquare(const int x, double epsilon = 0.0001) {
    double squareRoot = 0;
    double L = 0, R = x;
    while (abs(squareRoot * squareRoot - x) > epsilon) {
        squareRoot = L + (R - L) / 2;
        if (squareRoot * squareRoot > x) {
            R = squareRoot;
        }
        else {
            L = squareRoot;
        }
    }
    return squareRoot;
}

unsigned long long int leetcode_solution(int x) {
    if (const unsigned long long int s = isSquare(x); s != 0) {
        return s;
    }
    else {
        return static_cast<int>(binarySearchSquare(x));
    }
}

void printTest(int x, double epsilon) {
    double root = binarySearchSquare(x, epsilon);
    cout << "Число: " << x << " \t";
    cout << std::setprecision(10) << std::fixed;
    cout << "Точность: " << epsilon << "\t " << "Корень: " << root;
    cout << " \tПроверка: " << root * root << endl;
}

void printTests(int x) {
    printTest(x, 0.01);
    printTest(x, 0.001);
    printTest(x, 0.0001);
    printTest(x, 0.00001);
    cout << "-----------------------------------------------------------------------------------\n";
}

int main() {
    int x;

    x = 3;
    printTests(x);

    x = 9;
    printTests(x);

    x = 16;
    printTests(x);

    x = 25;
    printTests(x);

    x = 64;
    printTests(x);

    x = 100;
    printTests(x);

    x = 121;
    printTests(x);

    return 0;
}