#include <iostream>
#include <cmath>


void print_number(int num) {  // This function print one of classes of number in vavilon description.
    for (int i = 0; i < num / 10; i++) {
        std::cout << '<';
    }
    for (int i = 0; i < num % 10; i++) {
        std::cout << 'v';
    }

}


int main() {

    int number, num_of_class, power_num;

    std::cin >> number;

    for (int i = log(number) / log(60); i >= 0; i--) {
        power_num = pow(60, i);
        print_number(number / power_num);
        number = number % power_num;
        if (i != 0) {
            std::cout << '.';
        }
    }

    return 0;
}
