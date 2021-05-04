#include <iostream>
#include <string>


int main() {
    bool is_all = false;
    std::string str;
    int counter = 1;

    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            counter++;
        }
    }

    std::cout << counter;

    return 0;
}
