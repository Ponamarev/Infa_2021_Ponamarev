#include <iostream>


/*Должны быть функции копирование,      +
добавление елементов в начало и конец,  +
удаление по номеру и по значению,       +
слияние, умножение на целое число.*/


struct Element {
    int current;
    Element* next_ptr = nullptr;
};


struct List {
    Element* end_ptr = nullptr;
    Element* start_ptr = nullptr;
    int lenght = 0 ;
};


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

    return new_list;
}


List* merge_lists(List* first_massive, List* second_massive) { //TO FIX!!!
    /*
    This function combines two arrays "first_massive" and "second_massive" into one.
    return List*.
    */
    List* merged_list = new List();

    List* copied_list_one = copy_list(first_massive);
    List* copied_list_two = copy_list(second_massive);

    if (first_massive->lenght > 0 && second_massive->lenght > 0) {
        merged_list->start_ptr = copied_list_one->start_ptr;
        copied_list_one->end_ptr->next_ptr = copied_list_two->start_ptr;
        merged_list->end_ptr = copied_list_two->end_ptr;
    }

    else if (first_massive->lenght == 0 && second_massive->lenght > 0) {
        merged_list = copied_list_two;
    }

    else if (first_massive->lenght > 0 && second_massive->lenght == 0) {
        merged_list = copied_list_one;
    }

    return merged_list;
}


List* multiplication(int multiplier, List* massive) { //TO FIX!!!
    /**/
    List* multiplied_list = new List();

    for (int num = 1; num <= multiplier; num++) {
        multiplied_list = merge_lists(multiplied_list, massive);
        print_list(multiplied_list, 1);
    }

    return multiplied_list;
}


int main() {
    std::cout << "This is testing mod." << std::endl << std::endl;

    List* asd = new List();
    std::cout << "We can create list and fill it up" << std::endl;
    append(2, asd);
    append(3, asd);
    appstart(1, asd);
    append(4, asd);
    append(5, asd);
    print_list(asd, 1);
    std::cout << std::endl;

    std::cout << "We can search element with current 2" << std::endl;
    std::cout << "It have number " << search_element_with_current(3, asd) << std::endl;
    std::cout << std::endl;

    std::cout << "We can remove element with current 2" << std::endl;
    print_list(asd, 1);
    remove_element_with_current(2, asd);
    print_list(asd, 1);
    std::cout << std::endl;

    std::cout << "We can copy this massive" << std::endl;
    print_list(copy_list(asd), 1);
    std::cout << std::endl;

    std::cout << "We can merge two lists." << std::endl;
    List* asdf = new List();
    append(123, asdf);
    List* asdfg = merge_lists(asd, asdf);
    print_list(asdfg, 1);
    std::cout << std::endl;

    std::cout << "We can multiply a list by a number." << std::endl;
    print_list(multiplication(3, asd), 1);
    std::cout << std::endl;




}
