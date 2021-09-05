#include <iostream>


int main() {
    int number, count_of_numbers = 0, input_number, answer = 0;
    double  everage;
    std::cin >> number;
    const int num = number;

    int array_1[num];
    for (int i = 0; i < number; i++) {
        std::cin >> input_number;
        array_1[i] = input_number;
        count_of_numbers += input_number;
    }

    everage = count_of_numbers / number;

    for(int i = 0; i < number; i++) {
        if(array_1[i] > everage) {
            answer += array_1[i];
        }
    }

    std::cout << answer;
}
