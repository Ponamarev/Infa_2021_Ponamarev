#include <iostream>
#include <string>


struct Element {
    int current;
    std::string name;
    Element* next_ptr = nullptr;
    bool empty = true;
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



class Hash_table {
private:
    int prime = 4;
    int alpha_hash = 3;
    int table_len = 10;
    int count_of_elements = 0;
    List* ptr_data = new List();


public:
        Hash_table() {
        for(int i = 0; i < table_len; i++) {
            append(0, ptr_data);
        }
    }


    ~Hash_table() {
        Element* ptr_element = ptr_data->start_ptr;
        Element* ptr_next_element = ptr_element->next_ptr;
        for(int i = 0; i < table_len; i++) {
            //delete[] ptr_element;   //��� ��� �������!!!!!!
            Element* ptr_element = ptr_next_element;
            if(i != table_len - 1) {
                ptr_next_element = ptr_next_element->next_ptr;
            }
        }

        delete [] ptr_data;
    }


    int hash_first(std::string name) {
        int hash = 0;
        for(int i = 0; i < name.length(); i++) {
            hash = (prime * hash + name[i]) % table_len;
        }
        return hash;
    }


    int hash_second(std::string name, int hash) {
        for(int i = 0; i < name.length(); i++) {
            hash = (prime * hash + alpha_hash) % table_len;
        }
        return hash;
    }


    void add_new_element_to_not_full_table(Element* elem, List* ptr_data, int table_len) {
    /*
    ��������� ����� ������� � �� ����������� �������.
    ���� ��� �����������, ��� ���� ��������� �����  - �� ������������!
    */
    int id = hash_first(elem->name);
    Element* ptr_element = search_element_with_number(id, ptr_data);

    if (table_len < count_of_elements) {
        if (not(ptr_element->empty)) {
            while (not(ptr_element->empty)) {
                id = hash_second(elem->name, id);
                Element* ptr_element = search_element_with_number(id + 1, ptr_data);
            }
        }
        //���������� ��������
        elem->next_ptr = ptr_element->next_ptr;
            if(id != 1) {
                search_element_with_number(id - 1  + 1, ptr_data)->next_ptr = elem;
                if (id + 1 == ptr_data->lenght) {
                    ptr_data->end_ptr = elem;
                    }
                }
            else {
                ptr_data->start_ptr = elem;
                }
            count_of_elements++;
            delete [] ptr_element;
            }
        else {
            std::cout << "The table is full!";}
    }


    void rehash(int new_len) {
    /*
    ������ ����� ������� � ����� �������.
    */
    List* new_ptr_list = new List();
        for (int i = 0; i < new_len; i++) {
            append(0, new_ptr_list);
        }
        //������� ��������� � ����� ������.
        Element* ptr_elem_old_data = ptr_data->start_ptr;
        Element* ptr_next_elem_old_data = ptr_elem_old_data;
        for (int i = 0; i < table_len; i++) {
            ptr_elem_old_data = ptr_next_elem_old_data;
            if (i != table_len - 1) {
                ptr_next_elem_old_data = ptr_elem_old_data->next_ptr;
            }
            if (not(ptr_elem_old_data->empty)) {
                add_new_element_to_not_full_table(ptr_elem_old_data, new_ptr_list, new_len);
            }
            else {
                delete [] ptr_elem_old_data;
            }
        }
        delete [] ptr_data;
        ptr_data = new_ptr_list;
    }


    void add_new_element(Element* elem) {
    /*
    ��������� ����� ������� � ��� �������.
    */

// �������� �� ������������� �������
    if (count_of_elements > 0.7 * table_len) {
        int new_len; // ��������!!!!!!!!!!
        if (table_len < 50) {
            new_len = table_len * 2;
        }
        else {
            new_len = table_len * 1.3;
        }

        List* new_ptr_list = new List();
        for (int i = 0; i < new_len; i++) {
            append(0, new_ptr_list);
        }
        //������� ��������� � ����� ������.
        Element* ptr_elem_old_data = ptr_data->start_ptr;
        Element* ptr_next_elem_old_data = ptr_elem_old_data;
        for (int i = 0; i < table_len; i++) {
            ptr_elem_old_data = ptr_next_elem_old_data;
            if (i != table_len - 1) {
                ptr_next_elem_old_data = ptr_elem_old_data->next_ptr;
            }
            if (not(ptr_elem_old_data->empty)) {
                add_new_element_to_not_full_table(ptr_elem_old_data, new_ptr_list, new_len);
            }
            else {
                delete [] ptr_elem_old_data;
            }
        }
        delete [] ptr_data;
        ptr_data = new_ptr_list;

    }
    add_new_element_to_not_full_table(elem, ptr_data, table_len);
    }


Element* search_elem(std::string name) {
    /*

    */
    int id = hash_first(name);
    if (search_element_with_number(id + 1, ptr_data)->name != name) {
        while(search_element_with_number(id + 1, ptr_data)->name != name) {
            id = hash_second(name, id);
        }
    }

    return search_element_with_number(id + 1, ptr_data);
}


};


int main() {
    std::cout << "Test mode" << std::endl;
    Hash_table table;
    std::string str = "1234454654";
    std::cout << "Maked table" << std::endl;

    std::cout << "The hash of string " << str << " is " << table.hash_first(str) << std::endl;

    return 0;
}
