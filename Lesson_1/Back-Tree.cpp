#include <iostream>


int main(){

    int lenght_rect, len;

    std::cin >> lenght_rect;
    for (int i = 0; i <= lenght_rect/2; i++) {
        for (int g = 0; g <= lenght_rect; g++) {
            len = (2*i) / 2;
            if (g >= len and g < lenght_rect - len) {
                std::cout << '*';
            }
            else{
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
