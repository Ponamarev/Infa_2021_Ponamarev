#include <iostream>
#include <cmath>


int main()
{

    double katet_1;
    double katet_2;

    std::cin >> katet_1 >> katet_2;
    double hepotenuse = sqrt(katet_1 * katet_1 + katet_2 * katet_2);
    std::cout << hepotenuse << std::endl;

    return 0;
}

