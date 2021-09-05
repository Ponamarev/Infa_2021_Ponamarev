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


void remove_element_with_current(int current, List* massive) {
    /*
    Removes the first element with the value "current" from the "massive" array.
    */
    remove_element_with_number(search_element_with_current(current, massive), massive);
}


List* copy_list(List* massive) {
    /*
    Creates a pointer to an array with the same values as in the "massive" array.
    */
    List* new_list = new List();
    Element* ptr_element_of_old_list = massive->start_ptr;

    if (massive->lenght > 0) {

        for (int num = 1; num <= massive->lenght; num++) {
            append(ptr_element_of_old_list->current, new_list);
            ptr_element_of_old_list = ptr_element_of_old_list->next_ptr;
        }
    }

    delete [] ptr_element_of_old_list;

    return new_list;
}


int pop(List* massive) {
    /*
    Выдает значение следующего элемента очереди, удаляя этот элемент.
    Будем считать следующим элементом -  первый в списке ( к нему есть функция, обращающаяся за 0(1))
    */
    int answer = 0;

    if (massive -> lenght != 0){
        answer = search_element_with_number(1, massive)->current;
        remove_element_with_number(1, massive);
    }
    else {
        std::cout << "This queue is empty" << std::endl;
    }

    return answer;
}


void push_queue(int current, List* massive) {
    /*
    Добавляет элемент в конец очереди.
    */
    append(current, massive);
}


bool empty_queue(List* massive) {
    /*
    Проверяет, пуста ли очередь
    */
    bool answer = false;

    if (massive->lenght == 0) {
        answer = true;
    }

    return answer;
}


Element* front_queue(List* massive) {
    /*
    Обращается к первому элементу очереди.
    */
    return search_element_with_number(1, massive);
}


Element* back_queue(List* massive) {
    /*
    Обращается к последнему элементу очереди.
    */
    return search_element_with_number(massive->lenght, massive);
}


int main() {
    List* massive = create_empty();

    std::cout << "Create queue" << std::endl;
    for (int i = 0; i < 6; i++) {
        push_queue(i, massive);
    }
    print_list(massive, true);

    std::cout << "using pop(): answer = " << pop(massive) << std::endl;
    print_list(massive, true);

    std::cout << "using pop(): answer = " << pop(massive) << std::endl;
    print_list(massive, true);

    std::cout << "using back_queue(): answer = " << back_queue(massive) << "   It's current = " << back_queue(massive)->current << std::endl;
    print_list(massive, true);

    std::cout << "using front_queue(): answer = " << front_queue(massive)  << "   It's current = " << front_queue(massive)->current << std::endl;
    print_list(massive, true);

    std::cout << "using empty_queue(): answer = " << empty_queue(massive) << std::endl;
    print_list(massive, true);

    return 0;
}



