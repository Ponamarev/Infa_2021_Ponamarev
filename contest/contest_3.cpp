#include <iostream>
#include <cstring>
#include <vector>


int charToInt(char c){
    return c - '0';
}
void show_vector(int num, std::vector<int> datas, std::vector<int> counts)
{
    for (int i = 0; i < num ; i++){
        std::cout << datas[i] << "  " << counts[i] << std::endl;}
}

int data_from_str(std::string str){
    int ans = 0;
    ans = ans + charToInt(str[1]) + charToInt(str[0]) * 10;
    ans = ans + (charToInt(str[4]) + charToInt(str[3]) * 10) * 32;
    ans = ans + (charToInt(str[9]) + charToInt(str[8]) * 10 + charToInt(str[7]) * 100 + charToInt(str[6]) * 1000 - 1500) * 32 * 13;

    return ans;
}


int main() {
    int max = 0;
    int last_data = 0;
    int first_data = 4000000;
    std::vector<int> datas;
    std::vector<int> counts;

    int num;
    int p;

    std::string str;
    int int_data;
    int count;
    int count_of_days = 0;


    std::cin >> num;

    for (int i = 0; i < num; i++) {
        std::cin >> str >> count;
        int_data = data_from_str(str);

        if (int_data > last_data) {
            last_data = int_data;
        }
        if (int_data < first_data) {
            first_data = int_data;
        }
        if (count > max) {
            max = count;
        }
        bool not_in_list = true;
        for (int j = 0; j < count_of_days; j++) {
                if (datas[j] == int_data) {
                    not_in_list = false;
                    if(count > counts[j]) {
                        counts[j] = count;
                    }
                }
            }
        if(not_in_list) {
            count_of_days++;
            datas.push_back(int_data);
            counts.push_back(count);
        }

    }

    //show_vector(num, datas, counts);


    std::cin >> p;

    int ans_count;

    for (int i = 0; i < p; i++) {
        std::cin >> str;
        int_data = data_from_str(str);
        ans_count = 0;
        int finded_max = 0;

        if (first_data - 1 <= int_data && int_data <= last_data) {
            for (int i = 0; i < count_of_days; i++) {
                if (datas[i] <= int_data && finded_max < counts[i]) {
                    finded_max = counts[i];
                }
            }

            ans_count = finded_max;
        }
        if (int_data > last_data) {
            ans_count = max;
        }

    std::cout << ans_count << std::endl;
    }

    //std::cout << data_from_str("01,01,1999") << std::endl;


}
