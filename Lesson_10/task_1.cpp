#include <iostream>


int main() {
    bool is_all = false;

    int number;
    int counter = 0;

    std::cin >> number;
    while (!(is_all)) {
        counter += number % 10;
        number /= 10;
        if (number == 0) {
            is_all = true;
        }
    }

    std::cout << counter;

    return 0;
}
