#include <iostream>


int main() {

    int number, multiplier = 2;

    std::cin >> number;

    while (number != 1) {
        if (number % multiplier == 0) {
            std::cout << multiplier << std::endl;
            number = number / multiplier;
        }
        else {
            multiplier++;
        }
    }

    return 0;
}
