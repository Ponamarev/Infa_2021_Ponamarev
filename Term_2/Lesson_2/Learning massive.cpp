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

    std::cout << x; // a = *arr[1] - ����������� a �������� 1 �������� �������.
                    // a = &arr[1] - ����������� a ������ 1 �������� �������.
                    // ������ ����� �������� a �� ������ �������� 1 ��������� �������.

    return 0;
}

