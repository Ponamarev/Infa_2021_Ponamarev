 #include <iostream>
#include <string>


struct Element {
    int current;
    std::string name = "";
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


void append(int current, std::string name, List* massive) {
    /*
    This function adds a new element with the value "current" to the end of the array "massive".
    */
    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;
    ptr_new_element->name = name;

    if (massive->lenght == 0) {
        massive->start_ptr = ptr_new_element;
    }

    else {
        massive->end_ptr->next_ptr = ptr_new_element;
    }
    massive->end_ptr = ptr_new_element;
    massive->lenght++;
    std::cout << massive->end_ptr->name << '\n';
}


void appstart(int current, std::string name, List* massive) {
    /*
    This function adds a new element with the value "current" to the beginning of the array "massive".
    */
    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;
    ptr_new_element->name = name;

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
        std::cout << ptr_element->name;

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


int main() {
    int count_of_villager;
    bool truth;
    List* massive = create_empty();

    int honey_of_vilager;
    std::string name_of_vilager;

    int count_of_days;

    std::cin >> count_of_villager >> truth;

    for (int i = 0; i < count_of_villager; i++) {
        std::cin >> name_of_vilager >> honey_of_vilager;
        append(honey_of_vilager, name_of_vilager, massive);
    }

    std::cin >> count_of_days;

    std::cout << count_of_days << '\n';

    for (int i = 1; i <= count_of_days; i++) {
        if (i <= count_of_villager) {
            if (search_element_with_number(i, massive)->current == 0) {
                truth = !(truth);
                if (truth == 1) {
                    search_element_with_number(i, massive)->current = 1;
                }
            }
            else {
                if (!(truth)) {
                    remove_element_with_number(i, massive);
                }
            }
        print_list(massive, true);
        std::cout << "truth " << truth << std::endl;
        }
    }

    Element* ptr_element = massive->start_ptr;

    for (int i = 0; i <= massive->lenght; i++) {
        std::cout << ptr_element->name << ' ' << ptr_element->current << std::endl;
        ptr_element = ptr_element->next_ptr;
    }

    delete ptr_element;

    for (int i = 1; i <= massive->lenght; i++) {
        remove_element_with_number(massive->lenght, massive);
    }

    delete massive;

    return 0;
}
