#include <iostream>


int main() {

    int number = 1, count_of_iven_numbers = 0;

    while (number != 0) {
        if (number % 2 == 0) {count_of_iven_numbers ++;}
        std::cin >> number;
    }

    std::cout << count_of_iven_numbers;

    return 0;
}
