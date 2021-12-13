#include<iostream>
#include<chrono>

template<class T>


T factorial_T(T num) {
    T answer;

    if(num == 1) {
        answer = 1;
    }
    else {
        answer = num * factorial_T(num - 1);
    }

    return answer;
}


int factorial_int(int num) {
    int answer;

    if(num == 1) {
        answer = 1;
    }
    else {
        answer = num * factorial_T(num - 1);
    }

    return answer;
}


auto test_func(auto factorial_, int count_of_tests, int test_number){
    auto begin = std::chrono::steady_clock::now();

    for(int i = 0; i < count_of_tests; i++) {
        factorial_(test_number);
    }

    auto end = std::chrono::steady_clock::now();

    return (end - begin) / count_of_tests;
}


int main() {
    int test_number = 10000;
    int count_of_tests = 10000000;


    std::cout << "Start tests." << std::endl;



    //auto begin = std::chrono::steady_clock::now();

    for(int i = 0; i < count_of_tests; i++) {
        factorial_T(test_number);
    }

   // auto end = std::chrono::steady_clock::now();
std::cout << "Start tests." << std::endl;

    //auto time_of_T_factorial = (end - begin) / count_of_tests;
std::cout << "Start tests." << std::endl;



    //auto begin1 = std::chrono::steady_clock::now();

    for(int i = 0; i < count_of_tests; i++) {
        factorial_int(test_number);
    }

   // auto end1 = std::chrono::steady_clock::now();

   // auto time_of_int_factorial = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1) / count_of_tests;

    //auto time_of_T_factorial = test_func(factorial_T, count_of_tests, test_number);
    //auto time_of_int_factorial = test_func(factorial_int, count_of_tests, test_number);

   // std::cout << time_of_int_factorial.count() << time_of_T_factorial.count() << std::endl;

}
