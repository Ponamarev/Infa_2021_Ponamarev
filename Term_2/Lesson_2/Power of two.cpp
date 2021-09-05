#include <iostream>
#include <string>


int main() {

    int number;
    bool is_it_a_power_of_two = false;
    std::string answer = "NO";

    std::cin >> number;
    while (number % 2 == 0) {
        if (number == 2) {is_it_a_power_of_two = true;}
        number = number / 2;
    }

    if (is_it_a_power_of_two) {answer = "YES";}
    std::cout << answer;

    return 0;
}
