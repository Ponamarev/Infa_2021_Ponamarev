#include <iostream>


/*
ƒолжны быть функции копирование,        +
добавление елементов в начало и конец,  +
удаление по номеру и по значению,       +
сли€ние, умножение на целое число.      +
*/


struct Element {
    int current;
    Element* next_ptr = nullptr;
};


struct List {
    Element* start_ptr = nullptr;
    Element* next_start_ptr = nullptr;
    int lenght = 0 ;
};


List* create_empty() {
    List* empty_list = new List();
    return empty_list;
}


void push(int current, List* massive) {    //OK.
    /*
    This function adds a new element with the value "current" to the end of the array "massive".
    */
    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;

    if (massive->lenght != 0) {
        massive->next_start_ptr = massive->start_ptr;
        ptr_new_element->next_ptr = massive->start_ptr;
    }

    massive->start_ptr = ptr_new_element;
    massive->lenght ++;
}


void delete_element_stack(List* massive) { //OK.
    /**/
    if (massive->lenght > 0) {
        delete [] massive->start_ptr;
        massive->start_ptr = massive->next_start_ptr;
        massive->lenght --;

        if (massive->lenght > 1) {
            massive->next_start_ptr = massive->next_start_ptr->next_ptr;
        }
    }
    else {
        std::cout << "This is empty list!!";

    }

}


Element* pick_stack(List* massive) {
    /**/
    return massive->start_ptr;
}


int pop_list(List* massive) {
    /**/
    int current = pick_stack(massive)->current;
    delete_element_stack(massive);

    return current;
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


int main() {
    List* asd = create_empty();
    push(1, asd);
    push(2, asd);
    push(3, asd);
    print_list(asd, 1);

    std::cout << "pick:" << pick_stack(asd)->current;

    std::cout << "Delete element" <<std::endl;
    delete_element_stack(asd);
    print_list(asd, 1);

    std::cout << "Update stack." <<std::endl;
    push(3, asd);
    std::cout << "pop "<< pop_list(asd) <<std::endl;
    std::cout << "pop "<< pop_list(asd) <<std::endl;
    std::cout << "pop "<< pop_list(asd) <<std::endl;
    print_list(asd, 1);
    }
