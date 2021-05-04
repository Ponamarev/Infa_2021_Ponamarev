#include <iostream>


int main() {
    int number;
    bool is_sorted_ = false;
    int count_of_true_pair = 0;
    int step_number;

    std::cin >> number;

    int* first_key = new int[number];
    int* second_key = new int[number];

    for (int i = 0; i < number; i++) {
        std::cin >> first_key[i];
    }
    for (int i = 0; i < number; i++) {
        std::cin >> second_key[i];
    }

    while (count_of_true_pair < number * number) {
        for (int i = 0; i < number - 1; i++) {
            if (first_key[i] > first_key[i + 1]) {
                step_number = first_key[i];
                first_key[i] = first_key[i + 1];
                first_key[i + 1] = step_number;

                step_number = second_key[i];
                second_key[i] = second_key[i + 1];
                second_key[i + 1] = step_number;
            }

            else if ((first_key[i] == first_key[i + 1]) && second_key[i] > second_key[i + 1]) {
                step_number = first_key[i];
                first_key[i] = first_key[i + 1];
                first_key[i + 1] = step_number;

                step_number = second_key[i];
                second_key[i] = second_key[i + 1];
                second_key[i + 1] = step_number;
            }
            else {
                // если использовать это далее, проверить, что с count_of_true_pair++;
            }
        }
        count_of_true_pair++;
    }

    for (int i = 0; i < number; i++) {
        std::cout << first_key[i];
        if (i < number) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < number; i++) {
        std::cout << second_key[i];
        if (i < number) {}
        std::cout << ' ';
    }
}
