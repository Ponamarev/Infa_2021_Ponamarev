#include <iostream>
#include <cmath>


double func(double x) {
    return pow(x - 1, 2);
}


double find_minimum(double a, double b, double accuracy) {
    /*
    Ищет минимум функции func на отрезке [a, b].
    С точностью accuracy по значению и по аргументу.
    */
    double c = (a + b) / 2;

    while (abs(func(c) - func(a)) + abs(func(c) - func(b)) > accuracy  ||
          ((func(c) - func(c - accuracy)) < 0 && (func(c) - func(c + accuracy)) > 0) ||
           ((func(c) - func(c - accuracy)) > 0 && (func(c) - func(c + accuracy)) < 0)) {
        if (func((c - accuracy)) < func(c)) {
            b = (c + b) / 2;
            std::cout << "b: " << b << std::endl;
        }
        if (func((c + accuracy)) < func(c)) {
            a = (c + a) / 2;
            std::cout << "a: " << a << std::endl;
        }

        c = (a + b) / 2;
    }

    return c;
}


int main() {
    std::cout << find_minimum(-10, 1, 0.00000001);
}
