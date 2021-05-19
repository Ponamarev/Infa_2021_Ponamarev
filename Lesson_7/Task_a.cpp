#include <iostream>


int main() {
    int a, b, c, d, x, answer = 2;

    std::cin >> a >> b >> c >> d >> x;

    if (a + x == b && c * x == d) {
        answer = 5;
    }
    else if (a + x == b || c * x == d) {
        answer = 4;
    }
    else if ( x == 1024) {
        answer = 3;
    }

    std::cout << answer;
}
