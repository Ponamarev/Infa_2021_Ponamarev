#include <iostream>


int num_in_massive(int y, int x, int lenght) {
    //��� ������� ���������� ����� ������ (������� � ����) � ������������ x � y
    //(������� � ����) � ������� ������ �����.
    return (y - 1) * lenght + x - 1;
}


int main() {

    int lenght;
    int number;

    std::cin >> lenght;

    //����� ���������� ������ ������� � ���� �� ������� ������ ������.
    int* ptr_matrix = new int[lenght * lenght];

    for (int i = 0; i < lenght * lenght; i++) {
        std::cin >> ptr_matrix[i];
    }

    for (int x = 1; x <= lenght; x++){
        for (int y = lenght; y >= 1 ; y--) {
            std::cout << ptr_matrix[num_in_massive(y, x, lenght)];

            if (y > 1) {
                std::cout << ' ';
            }
            else {
                std::cout << std::endl;
            }
}
    }
}
