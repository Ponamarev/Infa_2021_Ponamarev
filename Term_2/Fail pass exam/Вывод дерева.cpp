#include <iostream>
//это дерево сравнения.

struct Element {
    Element* left_ptr = nullptr;
    Element* right_ptr = nullptr;
    Element* reletiv_ptr = nullptr;
    int current;
};

/*

add_value +
find_value +
remove_by_value
pre_order +
inf_order
post_order +
find_all_leaves - найти все значения "листьев" - концов дерева.
*/



struct BinTree {
    Element* rode = nullptr;
};


BinTree* create_empty() {
    BinTree* ptr_element = new BinTree();

    return ptr_element;
}


void add_value(int current, BinTree* tree) {
    //Добавляет элемент вправо, если оно больше значения над ним
    //Влево, если меньше.

    Element* ptr_new_element = new Element();
    ptr_new_element->current = current;
    bool is_finded_place = false;

    if (tree->rode != nullptr){
        Element* ptr_element = tree->rode;

        while (!(is_finded_place)) {
            if (current < ptr_element->current) {
                if (ptr_element->left_ptr == nullptr) {
                    ptr_element->left_ptr = ptr_new_element;
                    ptr_new_element->reletiv_ptr = ptr_element;
                    is_finded_place = true;
                }
                else {
                    ptr_element = ptr_element->left_ptr;
                }
            }
            else {
                if (ptr_element->right_ptr == nullptr) {
                    ptr_element->right_ptr = ptr_new_element;
                    ptr_new_element->reletiv_ptr = ptr_element;
                    is_finded_place = true;
                }
                else {
                    ptr_element = ptr_element->right_ptr;
                }
            }
        }
    }
    else {
        tree->rode = ptr_new_element;
    }
}


Element* find_value(int current, BinTree* tree) {
    /*
    current: Значение, ячейка с которой ищется.
    tree: Дерево, в котором ведется поиск.
    return: Возращает ссылку на элемент дерева, в котором лежит этом элемент.
    Если такового элемента нет, то возращает nullptr.
    */
    Element* ptr_element = nullptr;

    if (tree->rode != nullptr) {
        ptr_element = tree->rode;

        bool is_fouded = false;

        while (!(is_fouded)) {
            if (current < ptr_element->current) {
                if (ptr_element->left_ptr != nullptr) {
                    ptr_element = ptr_element->left_ptr;
                }
                else {
                    is_fouded = true;
                    ptr_element = nullptr;
                }
            }
            if (current == ptr_element->current) {
                is_fouded = true;
            }
            if (current > ptr_element->current) {
                if (ptr_element->right_ptr != nullptr) {
                    ptr_element = ptr_element->right_ptr;
                }
                else {
                    is_fouded = true;
                    ptr_element = nullptr;
                }
            }
        }
    }

    return ptr_element;
}



void remove_by_value(int value, BinTree* tree) {
    /*

    */

    Element* ptr_removed_element = find_value(value, tree);
    Element* ptr_element = ptr_removed_element;

    bool is_finded = false;

    if (ptr_element->right_ptr != nullptr) {
        ptr_element = ptr_element->right_ptr;

        while (!(is_finded)) {
            if (ptr_element->left_ptr == nullptr) {
                is_finded = true;
            }
            else {
                ptr_element = ptr_element->left_ptr;
            }
        }

        ptr_removed_element->current = ptr_element->current;

        ptr_element->reletiv_ptr->left_ptr = nullptr;
        delete[] ptr_element;

    }
    else if (ptr_removed_element->left_ptr != nullptr) {
        ptr_element = ptr_removed_element->left_ptr;
        if (ptr_removed_element != tree->rode) {
            if (ptr_removed_element->current < ptr_removed_element->reletiv_ptr->current) {
                ptr_removed_element->reletiv_ptr->left_ptr = ptr_element;
            }
            else {
                ptr_removed_element->reletiv_ptr->right_ptr = ptr_element;
            }

            ptr_element->reletiv_ptr = ptr_removed_element->reletiv_ptr;
        }
        else {
            ptr_element->reletiv_ptr = nullptr;
            tree->rode = ptr_element;
        }

        delete[] ptr_removed_element;
    }
    else {
        if (ptr_removed_element->reletiv_ptr == tree->rode) {
            tree->rode = nullptr;
        }
        else {
            if(ptr_removed_element->current < ptr_removed_element->reletiv_ptr->current) {
                ptr_removed_element->reletiv_ptr->left_ptr = nullptr;
            }
            else {
                ptr_removed_element->reletiv_ptr->right_ptr = nullptr;
            }
        }
    }
}


void pre_order(Element* tree) {
    /*

    */
    std::cout << tree->current << std::endl;

    if (tree->left_ptr != nullptr) {
        pre_order(tree->left_ptr);
    }

    if (tree->right_ptr != nullptr) {
        pre_order(tree->right_ptr);
    }
}


void post_order(Element* tree) {
    /*

    */

    if (tree->right_ptr != nullptr) {
        post_order(tree->right_ptr);
    }
    if (tree->left_ptr != nullptr) {
        post_order(tree->left_ptr);
    }
    std::cout << tree->current << std::endl;
}


void inf_order(Element* tree) {
    /*

    */

    if (tree->left_ptr != nullptr) {
        inf_order(tree->left_ptr);
    }

    std::cout << tree->current << std::endl;

    if (tree->right_ptr != nullptr) {
        inf_order(tree->right_ptr);
    }
}


void printing_under_tree(Element* rode) {
    /*
    Выводит элементы дерева.
    rode - указатель на корень дерева.
    */
    if (rode != nullptr) {
        std::cout << rode->current;

        if (rode->right_ptr != nullptr) {
            printing_under_tree(rode->right_ptr);
        }
        if (rode->left_ptr != nullptr) {
            printing_under_tree(rode->left_ptr);
        }
    }
}


void printing_tree(BinTree* tree) {
    /*
    Выводит элементы дерева.
    tree - указатель на дерево.
    */
    if (tree->rode != nullptr) {
        printing_under_tree(tree->rode);
    }
}



int main() {
    BinTree* tree = create_empty();

    for (int i = 5; i > 0; i--) {
        add_value(i, tree);
    }

    add_value(6, tree);

    printing_tree(tree);

    return 0;
}
