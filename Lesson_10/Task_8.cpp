#include <iostream>


int main() {
    int count_of_numbers;
    int reaserched_number;
    int step_number;
    int answer = -1;

    std::cin >> count_of_numbers >> reaserched_number;
    for (int i = 1; i <= count_of_numbers; i++) {
        std::cin >> step_number;
        if (step_number == reaserched_number) {
            answer = i;
        }
    }

    std::cout << answer;
}
