#include <iostream>
//��� ��������� ������ ������ � ������ ������� ����������, � �� ������ ������� �� �� ����� ������������.


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

    //��������� �������� ��������� �� ������ ������ ������� �������.
    ptr_new_element->next_ptr = massive->start_ptr;
    //������ ��������� ������� �� ����� ������ �������.
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
            //������ �������, ������ �� ����������.
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


void reverse_list(List* massive) {
    /**/
    Element* ptr_element;
    Element* old_next_ptr_element;
    Element* old_prew_ptr_element;

    ptr_element = massive->start_ptr;
    old_next_ptr_element = ptr_element->next_ptr;
    ptr_element->next_ptr = nullptr;

    for (int i = 1; i < massive->lenght; i++)
    {
        old_prew_ptr_element = ptr_element;
        ptr_element = old_next_ptr_element;
        old_next_ptr_element = old_next_ptr_element->next_ptr;

        //��������� ��������� � ���������� �� ���������� �������.
        ptr_element->next_ptr = old_prew_ptr_element;
    }

    //�������� ��������� ������� �� ����� � �� ������ �������.
    old_next_ptr_element = massive->end_ptr;
    old_prew_ptr_element = massive->start_ptr;

    massive->end_ptr = old_prew_ptr_element;
    massive->start_ptr = old_next_ptr_element;
}


List* merge_lists(List* first_massive, List* second_massive) {
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

    merged_list->lenght = first_massive->lenght + second_massive->lenght;

    delete [] copied_list_one;
    delete [] copied_list_two;

    return merged_list;
}


List* multiplication(int multiplier, List* massive) {
    /*
    This function returns an array containing multiple (multiplier) the elements of the "massive" array are repeated once.
    */
    List* multiplied_list = new List();

    for (int num = 1; num <= multiplier; num++) {
        multiplied_list = merge_lists(multiplied_list, massive);
    }

    return multiplied_list;
}



void buble_sort(List* massive, bool increase, bool visual) {
    /*
    ��������� ������ �� ������������ ������ massive
    increase - ���� true, �� ���������� �� �����������, ���� false, �� �� ��������.
    */
    int step_number;
    Element* ptr_element = nullptr;
    bool is_massive_sort = false;
    int i = 0;

    while (!(is_massive_sort)) {
        is_massive_sort = true; //���� ����� ������������, �� ���������� ������� �� false.
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


void appropriate_buble_sort(List* massive, List* appropriate_massive, bool increase, bool visual) {
    /*
    ��������� ������ �� ������������ ������ massive
    increase - ���� true, �� ���������� �� �����������, ���� false, �� �� ��������.
    */
    if (appropriate_massive->lenght >= massive->lenght) {
        int step_number;
        Element* ptr_element = nullptr;
        Element* appropriate_ptr_element = nullptr;
        bool is_massive_sort = false;
        int i = 0;

        while (!(is_massive_sort)) {
            is_massive_sort = true; //���� ����� ������������, �� ���������� ������� �� false.
            for (int i = 1; i < massive->lenght; i++) {
                ptr_element = search_element_with_number(i, massive);
                appropriate_ptr_element = search_element_with_number(i, appropriate_massive);

                if ((increase && (ptr_element->current > ptr_element->next_ptr->current))||
                    (!(increase) && (ptr_element->current < ptr_element->next_ptr->current))) {
                    step_number = ptr_element->current;
                    ptr_element->current = ptr_element->next_ptr->current;
                    ptr_element->next_ptr->current = step_number;

                    step_number = appropriate_ptr_element->current;
                    appropriate_ptr_element->current = appropriate_ptr_element->next_ptr->current;
                    appropriate_ptr_element->next_ptr->current = step_number;

                    is_massive_sort = false;
                }

            }
            if (visual) {
                std::cout << "First: ";
                print_list(massive, true);

                std::cout << "Second: ";
                print_list(appropriate_massive, true);
            }
        }

    }
    else {std::cout << "Appropriate massive longer, that main massive!" << std::endl;}

}


int main() {
    std::cout << "This is testing mod." << std::endl << std::endl;

    List* asd = new List();
    List* sdf = new List();

    std::cout << "We can create 2 list's and fill it up" << std::endl;
    std::cout << "First:  ";
    for (int i = 0; i < 10; i++) {append(i, asd);}
    print_list(asd, 1);

    std::cout << "Second: ";
    for (int i = 9; i >= 0; i--) {append(i, sdf);}
    print_list(sdf, 1);
    std::cout << std::endl;

    std::cout << "We can use appropriate_buble_sort for this massives:" << std::endl;
    std::cout << "It working? if lenght of appropriate massive longer that main massive :" << std::endl;
    appropriate_buble_sort(asd, sdf, false, false);

    std::cout << "First:  ";
    print_list(asd, 1);

    std::cout << "Second: ";
    print_list(sdf, 1);
    std::cout << std::endl;
}
