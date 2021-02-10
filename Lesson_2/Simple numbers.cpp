#include <iostream>
#include <cmath>


int main() {

    int number;
    bool answer = true;

    std::cin >> number;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            answer = false;
        }
    }
    std::cout << answer;


    return 0;
}
