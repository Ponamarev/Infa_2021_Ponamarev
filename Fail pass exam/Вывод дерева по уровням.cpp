#include <iostream>
#include <cmath>

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
    int left_height = 0;
    int right_height = 0;
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
    int depth = 1;

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
                    depth++;
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
                    depth++;
                }
            }
        }
        //изменяем высоту дерева.
        if (current < tree->rode->current && depth > tree->left_height) {
            tree->left_height = depth;
        }
        if (current > tree->rode->current && depth > tree->right_height)
            tree->right_height = depth;
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


int search_current_of_maximum(BinTree* tree) {
    /*
    Выдает значение максимального элемента данного дерева.
    */
    Element* ptr_element = tree->rode;
    bool is_finded = false;

    while(!(is_finded)) {
        if (ptr_element->right_ptr == nullptr) {
            is_finded = true;
        }
        else {
            ptr_element = ptr_element->right_ptr;
        }
    }

    return ptr_element->current;
}


int search_current_of_minimum(BinTree* tree) {
    /*
    Выдает значение минимального элемента данного дерева.
    */
    Element* ptr_element = tree->rode;
    bool is_finded = false;

    while(!(is_finded)) {
        if (ptr_element->left_ptr == nullptr) {
            is_finded = true;
        }
        else {
            ptr_element = ptr_element->left_ptr;
        }
    }

    return ptr_element->current;
}


Element* search_maximum(BinTree* tree) {
    /*
    Выдает максимальный элемент данного дерева.
    */
    Element* ptr_element = tree->rode;
    bool is_finded = false;

    while(!(is_finded)) {
        if (ptr_element->right_ptr == nullptr) {
            is_finded = true;
        }
        else {
            ptr_element = ptr_element->right_ptr;
        }
    }

    return ptr_element;
}


Element* search_minimum(BinTree* tree) {
    /*
    Выдает минимальный элемент данного дерева.
    */
    Element* ptr_element = tree->rode;
    bool is_finded = false;

    while(!(is_finded)) {
        if (ptr_element->left_ptr == nullptr) {
            is_finded = true;
        }
        else {
            ptr_element = ptr_element->left_ptr;
        }
    }

    return ptr_element;
}


int height_of_tree(Element* tree) {
    /*
    Возращает максимальную длину ветви дерева ( считая элементы, кроме корня).
    Пример слева самая длинная ветвь с длиной из 3 элементов, справа из 4 => ответ 4;
    */
    int height = 0;
    if (tree->left_ptr != nullptr && tree->right_ptr != nullptr) {
        if (tree->left_ptr > tree->right_ptr) {
            height = height_of_tree(tree->left_ptr) + 1;
        }
        else {
            height = height_of_tree(tree->right_ptr) + 1;
        }
    }
    else {
        if (tree->left_ptr != nullptr) {
            height = height_of_tree(tree->left_ptr) + 1;
        }
        if (tree->right_ptr != nullptr) {
            height = height_of_tree(tree->right_ptr) + 1;
        }
    }

    return height;
}


void right_balance(Element* tree) {
    /*
    Делает R балансировку для конкретного элемента дерева.
    */
    if (tree->left_ptr != nullptr) {
        Element* ptr_Y_element = tree->left_ptr;

        ptr_Y_element->reletiv_ptr = tree->reletiv_ptr;
        if (ptr_Y_element->reletiv_ptr != nullptr) {
            if (ptr_Y_element->current < ptr_Y_element->reletiv_ptr->current) {
                ptr_Y_element->reletiv_ptr->left_ptr = ptr_Y_element;
            }
            else {
                ptr_Y_element->reletiv_ptr->right_ptr = ptr_Y_element;
            }
        }
        tree->reletiv_ptr = ptr_Y_element;

        tree->left_ptr = ptr_Y_element->right_ptr;
        if (ptr_Y_element->right_ptr != nullptr) {
            ptr_Y_element->right_ptr->reletiv_ptr = tree;
        }

        ptr_Y_element->right_ptr = tree;
    }
}


void left_balance(Element* tree) {
    /*
    Делает L балансировку для конкретного элемента дерева.
    */
    if (tree->right_ptr != nullptr) {
        Element* ptr_Y_element = tree->right_ptr;

        ptr_Y_element->reletiv_ptr = tree->reletiv_ptr;
        if (ptr_Y_element->reletiv_ptr != nullptr) {
            if (ptr_Y_element->current < ptr_Y_element->reletiv_ptr->current) {
                ptr_Y_element->reletiv_ptr->right_ptr = ptr_Y_element;
            }
            else {
                ptr_Y_element->reletiv_ptr->left_ptr = ptr_Y_element;
            }
        }
        tree->reletiv_ptr = ptr_Y_element;

        tree->left_ptr = ptr_Y_element->left_ptr;
        if (ptr_Y_element->left_ptr != nullptr) {
            ptr_Y_element->left_ptr->reletiv_ptr = tree;
        }

        ptr_Y_element->left_ptr = tree;
    }
}


bool is_balansed(Element* tree) {
    /*
    Проверяет, сбалансированно ли дерево.
    */
    bool answer = true;

    if (height_of_tree(tree->right_ptr) - height_of_tree(tree->left_ptr) > 1 &&
         height_of_tree(tree->right_ptr) - height_of_tree(tree->left_ptr) < -1) {
        answer = false;
    }

    return answer;
}


void printing_tree_by_levels(BinTree* tree) {
    /*
    Выводит дерево по уровням.
    tree - указатель на дерево.
    */
    if (tree->rode != nullptr) {
        int height = height_of_tree(tree->rode);
        unsigned number = pow(2, height);

        Element** massive = new Element*[number];
        Element** step_massive = new Element*[number];

        massive[0] = tree->rode;
        for (int f = 0; f <= (pow(2, height)) / 2; f++) {std::cout << ' ';}
        std::cout << tree->rode->current << std::endl;

        for (int i = 0; i < height; i++) {
            //создает новый массив указателей на элементы уровнем ниже.
            for (int g = 0; g < pow(2, i); g++) {
                if (massive[g] != nullptr && massive[g]->left_ptr != nullptr) {
                    step_massive[2 * g] = massive[g]->left_ptr;
                }
                else {step_massive[2 * g] = nullptr;}

                if (massive[g] != nullptr && massive[g]->right_ptr != nullptr) {
                    step_massive[2 * g + 1] = massive[g]->right_ptr;
                }
                else {step_massive[2 * g + 1] = nullptr;}
            }

            //Сдвинем начало строки так, чтобы он рисовался в виде дерева.
            for (int f = 0; f <= (pow(2, height) - pow(2, i + 1)) / 2;f++) {
                std::cout << ' ';
            }

            //Складывает новый массив указателей в старый и выводит значения.
            for (int j = 0; j < pow(2, i + 1); j++) {
                massive[j] = step_massive[j];

                if (massive[j] != nullptr) {
                    std::cout << massive[j]->current;
                }
                else {
                    std::cout << ' ';
                }
                if (j != pow(2, i + 1) - 1) {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;

        }
    }
}


void print_Tree_1(Element* tree, int level)
{
    if(tree != nullptr) {
        print_Tree_1(tree->right_ptr, level + 1);
        for(int i = 0; i < level; i++) {std::cout << "   ";}
        std::cout << tree->current << std::endl;
        print_Tree_1(tree->left_ptr, level + 1);
    }
}


int main() {
    BinTree* tree = create_empty();

    for (int i = 5; i > 0; i--) {
        add_value(i, tree);
    }

    add_value(6, tree);
    add_value(10, tree);
    add_value(7, tree);
    add_value(8, tree);

    printing_tree_by_levels(tree);
    //print_Tree_1(tree->rode, 1);

    return 0;
}
