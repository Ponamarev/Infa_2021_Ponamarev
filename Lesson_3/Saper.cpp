#include <iostream>


int num_of_point_in_massive_of_map(int y, int x, int lenght_x) {
    //Ёта функци€ возвращает номер клетки (начина€ с нул€) с координатами x и y
    //(начина€ с нул€) в массиве клеток карты.
    return (y - 1) * lenght_x + x - 1;
}


int main() {
    int lenght_y, lenght_x;
    int count_of_bomb;
    int coord_y, coord_x;

    std::cin >> lenght_y >> lenght_x;
    std::cin >> count_of_bomb;

    //Ѕудем нумеровать клетки начина€ с нул€ по строкам справа налево.
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

    //ѕереберем все клетки карты.
    for (int x = 1; x <= lenght_x; x++) {
        for (int y = 1; y <= lenght_y; y++){

            //≈сли в клетке есть бомба, то всем соседним (если таковые есть) нужно добавить 1 в ответе.
            //ѕроверка на наличие бомбы.
            if (ptr_map_of_bombs[num_of_point_in_massive_of_map(y, x, lenght_x)] == -1) {

                for (int x_k = -1; x_k < 2; x_k++) {
                    //ѕроверка на не выход за границы карты по х.
                    if ((x_k + x) > 0 && (x_k + x) <= lenght_x) {
                        for (int y_k = -1; y_k < 2; y_k++) {

                            //ѕроверка на не выход за границы карты по у.
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
