#include <iostream>
#include <vector>
#include <cmath>


int main() {
    int num;
    int len = 0;
    int answer = -1;
    std::vector <int> data(1);

    std::cin >> num;

    do {
        if (num == 0) {
            break;
        }
        if (num > 0) {
            data.push_back(num);
            len++;
        }
        else if (abs(num) < data.back() && len > 0) {
            int n = data.at(len);
            data.at(len) = n + num;
        }
        else if (len > 0){
            data.pop_back();
            len--;
        }
        std::cin >> num;
     } while (num != 0);

    if (len > 0) {
        answer = data.back();
    }
    std::cout << len << ' ' << answer;

    return 0;
}
