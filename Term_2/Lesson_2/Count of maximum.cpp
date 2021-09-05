#include <iostream>


int main() {

    int number = -1, maximum = 0, count_of_maximum = 0;

    while (number != 0) {
            if (maximum < number) {
                count_of_maximum = 1;
                maximum = number;
            }
            else if (maximum == number) {
                count_of_maximum++;
            }

        std::cin >> number;
    }

    std::cout << count_of_maximum;

    return 0;
}
