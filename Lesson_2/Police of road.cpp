#include <iostream>
#include <string>


int main() {

    std::string number = "A123AA";
    int velocity = 0, counter = 0;

    while (number != "A999AA") {
        if (velocity > 60) {
            if (number[1] == number[2] && number[2] == number[3]) {
                counter += 1000;
            }
            else if (number[1] == number[2] || number[2] == number[3] || number[3] == number[1]) {
                counter += 500;
            }
            else {
                counter += 100;
            }
        }

        std::cin >> velocity >> number;
    }

    std::cout << counter;

    return 0;
}
