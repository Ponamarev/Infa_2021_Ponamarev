#include <iostream>
#include <cmath>


int main()
{

    float katet_1;
    float katet_2;

    std:: cin >> katet_1 >> katet_2;
    float hepotenuse = sqrt(katet_1 * katet_1 + katet_2 * katet_2);
    std:: cout << hepotenuse << std::endl;

    return 0;
}

