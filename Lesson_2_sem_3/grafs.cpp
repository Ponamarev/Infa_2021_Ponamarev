#include <iostream>
#include <vector>


class Graff {
public:
    int count_of_vertex = 0;
    std::vector <std::vector <bool>> matrix;

    Graff(std::vector <std::vector <bool>> inialiase_matrix) {
        bool inited = true;
        count_of_vertex = inialiase_matrix.size();
        //Checking for the correctness of the obtained matrix.
        for (int i = 0; i < count_of_vertex; i++) {
            if (inialiase_matrix.at(i).size() != count_of_vertex) {
                inited = false;
            }
        }
        if (inited) {
            matrix = inialiase_matrix;
        }
    }


    Graff(int count) {
        //create graff with "count" elements, that have not neighbours.
        std::vector <std::vector <bool>> _matrix_(count);
        //Create matrix.
        for (int i = 0; i < count; i++) {
            std::vector <bool> vect(count);
            _matrix_.at(i) = vect;
            }
        matrix = _matrix_;
    }


    Graff() {}


    void print(){
        for(int i = 0; i < count_of_vertex; i++){
            for (int j = 0; j < count_of_vertex; j++){
                std::cout << matrix.at(i).at(j) << " ";
            }
            std::cout << std::endl;
            }
        std::cout << std::endl;
    }

};


class Parent_class {
public:
    std::vector <bool> pointed_list;
    int count_of_elems;
    Graff graff;

    Parent_class(Graff graff_){
        graff = graff_;
        pointed_list = std::vector<bool>(graff.count_of_vertex);     //std::vector <bool> pointed_list(graff.count_of_vertex);
        count_of_elems = graff.count_of_vertex;
    }

};


class DFS_search : public Parent_class {

public:
    DFS_search(Graff graff_) : Parent_class(graff_){}


    void print_in_depth(int number_of_vertex) {
        if (pointed_list[number_of_vertex] == false) {
            std::cout << "vertex number " << number_of_vertex << std::endl;
            pointed_list.at(number_of_vertex) = true;
            for (int i = 0; i < count_of_elems; i++) {
                if (graff.matrix.at(number_of_vertex).at(i)) {
                    print_in_depth(i);
                }
            }
        }
    }

};


class BFS_seacher : public Parent_class{
public:
    std::vector <std::vector <int>> output_list;

    BFS_seacher(Graff graff_) : Parent_class(graff_) {
        output_list = std::vector<std::vector <int>>(count_of_elems);     //std::vector <bool> pointed_list(graff.count_of_vertex);

        /*for (int i = 0; i < count_of_elems; i++) {
            std::vector <bool> elem(count_of_elems);
            output_list.at(i) ;
        }*/
        }



    void breadth_search(int number_of_elem) {
        int num = 0;

        __breadth_search(number_of_elem, num);

        for(int y = 0; y < count_of_elems; y++) {
                for(int u = 0; u < count_of_elems; u++) {
                    if (output_list[y][u] != 0) {
                        std::cout << output_list[y][u] << "  ";
                    }
                }
                std::cout << std::endl;
            }
    }


    void __breadth_search(int number_of_elem, int num) {
        if (pointed_list[number_of_elem] == false) {
            pointed_list[number_of_elem] == true;
            output_list.at(num).push_back(number_of_elem);
            num++;
            for (int i = 0; i < count_of_elems; i++) {
                if (graff.matrix.at(number_of_elem).at(i) && num < 10) {
                    __breadth_search(i, num);
                }
            }

        }
    }
};


std::vector <std::vector <bool>> new_elem(std::vector <std::vector <bool>> _matrix_, int elem_1, int elem_2) {
    //adds element 1 to the neighbors of element 2.
    _matrix_.at(elem_1).at(elem_2) = 1;
    _matrix_.at(elem_2).at(elem_1) = 1;

    return _matrix_;
}


int main() {
    int count = 10;
    std::vector <std::vector <bool>> _matrix_(count);
    //Create matrix.
    for (int i = 0; i < count; i++) {
        std::vector <bool> vect(count);
        _matrix_.at(i) = vect;
        }
    _matrix_ = new_elem(_matrix_, 1, 2);
    _matrix_ = new_elem(_matrix_, 1, 3);
    _matrix_ = new_elem(_matrix_, 1, 4);
    _matrix_ = new_elem(_matrix_, 2, 3);
    _matrix_ = new_elem(_matrix_, 3, 4);

    Graff graff(_matrix_);
    graff.print();

    DFS_search sdf(graff);
    sdf.print_in_depth(1);

    BFS_seacher dfg(graff);
    dfg.breadth_search(1);

}
