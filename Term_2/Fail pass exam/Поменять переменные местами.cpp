#include <iostream>


int main() {
    int a;
    int b;

    std::cin >> a >> b;

    a = b - a;
    b = b - a;
    a = a + b;

    std::cout << a << ' ' << b << std::endl;
}
