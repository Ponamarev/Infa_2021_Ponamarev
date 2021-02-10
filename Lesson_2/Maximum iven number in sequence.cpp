#include <iostream>


int main(){

    int number = -1, answer = 0;

    while ( number != 0) {
        if (number % 2 == 0 && number > answer) {answer = number;}
        std::cin >> number;
    }

    std::cout << answer;

    return 0;
}
