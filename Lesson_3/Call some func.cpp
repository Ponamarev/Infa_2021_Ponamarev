#include <iostream>


 int do_some_awesome_work(int number_1, int number_2);


 int main() {
    int number_1, number_2, answer;

    std::cin >> number_1 >> number_2;

    answer = do_some_awesome_work(number_1, number_2);

    std::cout << answer;
 }
