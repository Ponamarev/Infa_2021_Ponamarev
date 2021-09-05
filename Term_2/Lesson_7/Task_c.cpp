#include <iostream>
#include <iomanip>
#include <cmath>

void print(double number) {
    if (int(number) ==  number) {
        std::cout << std::fixed << std::setprecision(1) << number;
    }
    else if (int(number * 10) == 10 * (number)) {
        std::cout << std::fixed << std::setprecision(1) << number;
    }
    else if (int(number * 100) == 100 * (number)) {
        std::cout << std::fixed << std::setprecision(2) << number;
    }
    else {
        std::cout << std::fixed << std::setprecision(3) << number;
    }



}

int main() {
    double number;
    double count_of_numbers = 0;
    double summ_of_square = 0;
    double summ = 0;

    double dispertion;
    double average;

    int dispertion_1;
    int average_1;

    std::cin >> number;

    while (number != 0) {
        summ += number;
        summ_of_square += number * number;
        count_of_numbers++;

        std::cin >> number;

    }

    //Посчитаем ответ.
    average = summ / count_of_numbers;
    dispertion = summ_of_square / count_of_numbers - average * average;

    //Округлим ответ.
    average = std::round(1000 * average) / 1000;
    dispertion = std::round(1000 * dispertion) / 1000;

    print(average);
    std::cout << ' ';
    print(dispertion);

    return 0;
}
