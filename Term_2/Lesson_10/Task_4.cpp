#include <iostream>
#include <string>


int main() {
    bool is_all = false;
    std::string str;
    int max_number = 0;
    int number = 0;

    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' or
            str[i] == '1' or
            str[i] == '2' or
            str[i] == '3' or
            str[i] == '4' or
            str[i] == '5' or
            str[i] == '6' or
            str[i] == '7' or
            str[i] == '8' or
            str[i] == '9'
            ) {
            number = number * 10 + (int)(str[i]) - 48;

        }
        else {
            number = 0;
        }

        if (number > max_number) {
            max_number = number;
        }
    }

    std::cout << max_number;

    return 0;
}
