#include <iostream>


int num_of_point_in_massive_of_map(int y, int x, int lenght_x) {
    //��� ������� ���������� ����� ������ (������� � ����) � ������������ x � y
    //(������� � ����) � ������� ������ �����.
    return (y - 1) * lenght_x + x - 1;
}


int main() {
    int lenght_y, lenght_x;
    int count_of_bomb;
    int coord_y, coord_x;

    std::cin >> lenght_y >> lenght_x;
    std::cin >> count_of_bomb;

    //����� ���������� ������ ������� � ���� �� ������� ������ ������.
    int* ptr_map_of_answer = new int[lenght_y * lenght_x];
    int* ptr_map_of_bombs = new int[lenght_y * lenght_x];

    for (int i = 0; i < lenght_y * lenght_x; i++) {
        ptr_map_of_answer[i] = 0;
        ptr_map_of_bombs[i] = 0;
    }

    for (int i = 0; i < count_of_bomb; i++) {
        std::cin >> coord_y >> coord_x;
        ptr_map_of_bombs[num_of_point_in_massive_of_map(coord_y, coord_x, lenght_x)] = -1;
    }

    //��������� ��� ������ �����.
    for (int x = 1; x <= lenght_x; x++) {
        for (int y = 1; y <= lenght_y; y++){

            //���� � ������ ���� �����, �� ���� �������� (���� ������� ����) ����� �������� 1 � ������.
            //�������� �� ������� �����.
            if (ptr_map_of_bombs[num_of_point_in_massive_of_map(y, x, lenght_x)] == -1) {

                for (int x_k = -1; x_k < 2; x_k++) {
                    //�������� �� �� ����� �� ������� ����� �� �.
                    if ((x_k + x) > 0 && (x_k + x) <= lenght_x) {
                        for (int y_k = -1; y_k < 2; y_k++) {

                            //�������� �� �� ����� �� ������� ����� �� �.
                            if ((y_k + y) > 0 && (y_k + y) <= lenght_y) {
                                ptr_map_of_answer[num_of_point_in_massive_of_map(y + y_k, x + x_k, lenght_x)] += 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < lenght_x * lenght_y; i++) {
        if(i % lenght_x == 0) {
            std::cout << std::endl;
        }
        if (ptr_map_of_bombs[i]) {
            std::cout << ptr_map_of_bombs[i];
        }
        else {
            std::cout << ptr_map_of_answer[i];
        }
    }
}
