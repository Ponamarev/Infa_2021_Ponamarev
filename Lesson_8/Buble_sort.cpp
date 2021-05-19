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


int search_element_with_current(int current, List* massive) {
    /*
    This function searches for the first element of the array "massive" with the value "current".
    return number of first location of element with this current (numbering starts with one).
    */
    bool is_searched = false;
    int number_of_element = -1;
    Element* ptr_element = massive->start_ptr;

    if (massive->lenght > 0) {
        for (int num = 1; num <= massive->lenght; num++) {
            if (ptr_element->current == current && is_searched == false) {
                is_searched = true;
                number_of_element = num;
                break;
            }

            ptr_element = ptr_element->next_ptr;
        }

        if (is_searched = false) {
            std::cout << "There is no element with this value in this array.";
        }

    }

    else {
        std::cout << "There are no elements in this array.";
    }

    delete [] ptr_element;

    return number_of_element;
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


void print_list(List* massive, bool end_line) {
    /*
    Displays the values of the "massive" array.
    */
    Element* ptr_element = massive->start_ptr;

    std::cout << '[';

    for (int num = 1; num <= massive->lenght; num++) {
        std::cout << ptr_element->current;

        if (num < massive->lenght) {
            std::cout << ", ";
        }

        ptr_element = ptr_element->next_ptr;
    }

    std::cout << ']';

    if (end_line) {
        std::cout << std::endl;
    }

    delete [] ptr_element;
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


void buble_sort(List* massive, bool increase, bool visual) {
    /*
    Принимает ссылку на динамический массив massive
    increase - если true, то сортировка по возрастанию, если false, то по убыванию.
    */
    int step_number;
    Element* ptr_element = nullptr;
    bool is_massive_sort = false;
    int i = 0;

    while (!(is_massive_sort)) {
        is_massive_sort = true; //Если будет перестановка, то поменяетс обранто на false.
        for (int i = 1; i < massive->lenght; i++) {
            ptr_element = search_element_with_number(i, massive);

            if ((increase && (ptr_element->current > ptr_element->next_ptr->current))||
                (!(increase) && (ptr_element->current < ptr_element->next_ptr->current))) {
                step_number = ptr_element->current;
                ptr_element->current = ptr_element->next_ptr->current;
                ptr_element->next_ptr->current = step_number;
                is_massive_sort = false;
            }

        }
        if (visual ) {
             print_list(massive, true);
        }
    }
}


int main() {
    List* massive = create_empty();
    appstart(19, massive);
    appstart(18, massive);
    appstart(17, massive);
    appstart(17, massive);
    appstart(14, massive);
    appstart(22, massive);
    appstart(45, massive);
    appstart(23, massive);
    appstart(87, massive);
    appstart(35, massive);
    appstart(94, massive);
    appstart(34, massive);
    appstart(37, massive);
    appstart(45, massive);
    appstart(94, massive);
    appstart(34, massive);
    appstart(64, massive);
    appstart(34, massive);
    appstart(98, massive);
    appstart(93, massive);
    appstart(74, massive);
    appstart(73, massive);
    appstart(84, massive);
    appstart(87, massive);
    appstart(23, massive);
    appstart(87, massive);
    appstart(34, massive);
    appstart(37, massive);
    appstart(45, massive);
    appstart(56, massive);
    appstart(79, massive);
    appstart(78, massive);
    appstart(78, massive);
    appstart(43, massive);
    append(1, massive);

    print_list(massive, true);
    buble_sort(massive, true, true);
}
