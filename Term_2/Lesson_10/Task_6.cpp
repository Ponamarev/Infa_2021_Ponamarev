#include <iostream>


int main() {
    bool is_finded = false;
    int num_n = 0;
    int num_n1 = 0;
    int num_n2 = 1;
    int num_n3 = 0;
    int answer = 3;
    int required_number;

    std::cin >> required_number;

    if (required_number <= num_n2) {
        is_finded = true;
        if (required_number < num_n) {answer = 0;}
        if (required_number < num_n1) {answer = 1;}
        if (required_number < num_n2) {answer = 2;}
    }

    while (!(is_finded)) {
        num_n3 = num_n + num_n1 + num_n2;
        if (required_number < num_n3) {
            is_finded = true;
        }
        else {
            answer++;
        }
        num_n = num_n1;
        num_n1 = num_n2;
        num_n2 = num_n3;
    }
    if (answer == 3) {answer++;}
    std::cout << answer;
}
