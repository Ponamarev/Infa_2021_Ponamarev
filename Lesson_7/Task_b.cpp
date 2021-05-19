#include <iostream>


int main() {
    int count_of_numbers, number;
    bool is_number_wrong;
    bool is_unfinded_number = true;

    std::cin >> count_of_numbers;

    for (int i = 0; i < count_of_numbers; i++) {
        is_number_wrong = false;

        std::cin >> number;
        int remain =  (number - number % 1000) / 1000;

        //Проверка на деление на 4:
        if (number % 4 == 0 && remain != 4 && remain != 5){
            is_number_wrong = true;
        }

        //Проверка на деление на 7:
        if (number % 7 == 0 && remain != 7 && remain != 1){
            is_number_wrong = true;
        }

        //Проверка на деление на 9:
        if (number % 9 == 0 && remain != 9 && remain != 8){
            is_number_wrong = true;
        }

        if (is_number_wrong) {
            std::cout << number << std::endl;
            is_unfinded_number = false;
        }
    }

    if (is_unfinded_number){
        std::cout << 0;
    }
}
