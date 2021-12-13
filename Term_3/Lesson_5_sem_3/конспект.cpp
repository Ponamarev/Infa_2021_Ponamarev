#include<iostream>


template<class TEMP> //Эта штука, которая создает штуку, которая говорит, что тип данных мы узнаем потом.
                    // Из - за нее функция будет компилироваться на месте, а не заранеее. Это должно увеличить время работы.

TEMP maximum(TEMP number_1, TEMP number_2) {

    TEMP answer;
    if (number_1 > number_2) {
        answer = number_1;
    }
    else {
        answer = number_2;
    }

    return answer;
}


int main() {
    int a = 12;
    int b = 43.5;
    std::cout << maximum(a, b);
}
