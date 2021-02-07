#include <iostream>


int main(){

    int lenght_rect;

    std::cin >> lenght_rect;
    for (int i = 0; i < lenght_rect; i++) {
        for (int g = 0; g <= i; g++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    return 0;
}

