#include <iostream>
#include <string>


int main() {
    unsigned int number_of_abonents;
    std::cin >> number_of_pairs;

    std::string* massive_name new  std::string[number_of_abonents];
    int* massive_num = new int[number_of_abonents];
    int* massive_sum = new int[number_of_abonents];

    std::string* top_name new  std::string[10];
    int* top_num = new int[10];
    int* top_sum = new int[10];

    std::string nane;
    int num;
    int sum;

    int max_sum = 0;

    for (int i = 0; i < number_of_abonents; i++) {
        std::cin >> name >> num >> sum;

        massive_name[i] = name;
        massive_num[i] = num;
        massive_sum[i] = sum;
    }

    for (int i = 0; i < number_of_abonents; i++) {
        if (massive_sum[i] > max_sum){
            name = massive_name[i];
            num = massive_num[i];
            sum = massive_sum[i];

            max_sum = sum;
        }
    }

}
