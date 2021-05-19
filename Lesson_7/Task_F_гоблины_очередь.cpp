#include <iostream>


struct Element {
    int current;
    Element* next_ptr = nullptr;
};


struct List {
    Element* end_ptr = nullptr;
    Element* start_ptr = nullptr;
    int lenght = 0 ;
};


List* create_empty() {
    List* empty_list = new List();
    return empty_list;
}


Element* search_element_with_number(int number, List* massive) {
    /*
    This function searches for the array element "massive" under the number "number" (numbering starts with one).
    */
    Element* ptr_element = massive->start_ptr;
    if (massive->lenght > 0 && number <= massive->lenght) {
        for (int i = 1; i < number; i++) {
            ptr_element = ptr_element->next_ptr;
        }
    }

    else if (massive->lenght == 0) {
        std::cout << "There are no elements in this array.";
    }

    else if (massive->lenght < number) {
        std::cout << "The index of the element extends beyond the array.";
    }

    return ptr_element;
}


void append(int current, List* massive) {
    /*
    This function adds a new element with the value "current" to the end of the array "massive".
    */
    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;

    if (massive->lenght == 0) {
        massive->start_ptr = ptr_new_element;
    }

    else {
        massive->end_ptr->next_ptr = ptr_new_element;
    }
    massive->end_ptr = ptr_new_element;
    massive->lenght ++;
}


void appstart(int current, List* massive) {
    /*
    This function adds a new element with the value "current" to the beginning of the array "massive".
    */
    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;

    if (massive->lenght == 0) {
        massive->end_ptr = ptr_new_element;
    }

    //Назначаем элементу указатель на бывший первый элемент массива.
    ptr_new_element->next_ptr = massive->start_ptr;
    //Меняем указатель массива на новый первый элемент.
    massive->start_ptr = ptr_new_element;
    massive->lenght ++;
}


void remove_element_with_number(int number, List* massive) {
    /*
    Removes the "number" element from the "massive" array.
    */
    Element* ptr_element = massive->start_ptr;

    if (number <= 0) {
        std::cout << "The array is numbered from one. Number " << number <<" entered";
    }

    else if (number > massive->lenght) {
        std::cout << "The index of the element extends beyond the array.";
    }

    else if (massive->lenght == 0) {
        std::cout << "There are no elements in this array.";
    }
    else {
        if (number == 1){
            massive->start_ptr = ptr_element->next_ptr;
        }

        else {
            //Найдем элемент, идущий до удаляемого.
            for (int num = 1; num < number - 1; num++) {
                ptr_element = ptr_element->next_ptr;
            }

            ptr_element->next_ptr = ptr_element->next_ptr->next_ptr;
        }

        massive->lenght --;
    }

    delete [] ptr_element;
}



void add_element_to_midle(int number, List* massive) {
    /*
    Добавляет элемент в очередь после центрального, если длина нечетная, или на центральное место, если четная.
    */
    Element* new_ptr = new Element();
    new_ptr->current = number;
    Element* ptr_middle;
    Element* ptr_apper_middle;

    if (massive->lenght % 2 == 1) {
        ptr_middle = search_element_with_number(massive->lenght / 2 + 1, massive);
        ptr_apper_middle = search_element_with_number(massive->lenght / 2 + 2, massive);
    }
    else {
        ptr_middle = search_element_with_number(massive->lenght / 2, massive);
        ptr_apper_middle = search_element_with_number(massive->lenght / 2 + 1, massive);
    }

    ptr_middle->next_ptr = new_ptr;
    new_ptr->next_ptr = ptr_apper_middle;

    massive->lenght ++;
}


void add_goblin_to_queque(int number, List* massive, bool permission) {
    /*
    Добавляет гоблинов в очередь по правилу:
    Привелегированных сразу после центра, если очередь нечетна, в центр, если четна.
    Других в конец.
    */
    if (permission) {
        if (massive->lenght == 0 or massive->lenght == 1) {
            append(number, massive);
        }
        else {
            add_element_to_midle(number, massive);
        }
    }
    else {
        append(number, massive);
    }
}


int main() {
    int count_of_cicles;
    char input;
    int number_of_goblin;
    List* queque = create_empty();

    std::cin >> count_of_cicles;

    for (int i = 0; i < count_of_cicles; i++) {
        std::cin >> input;
        if (input == '+') {
            std::cin >> number_of_goblin;
            add_goblin_to_queque(number_of_goblin, queque, false);
        }
        if (input == '*') {
            std::cin >> number_of_goblin;
            add_goblin_to_queque(number_of_goblin, queque, true);
        }
        if (input == '-') {
            std::cout << queque->start_ptr->current << std::endl;
            remove_element_with_number(1, queque);
        }
    }
}
