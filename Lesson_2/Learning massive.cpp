#include <iostream>
#include <string>


int tack1(){

    int64_t arr[100] = {1,2,3,4,5,6,7,7,7};

    std::cout << sizeof(arr) / 8;

    return 0;
}

int main(){

    int64_t arr[100] = {1,2,3,4,5,6,7,7,7};
    auto x = arr;

    std::cout << x; // a = *arr[1] - присваивает a значение 1 элемента массива.
                    // a = &arr[1] - присваивает a АДРЕСС 1 элемента массива.
                    // Теперь меняя значение a мы меняем значение 1 эелемента массива.

    return 0;
}

