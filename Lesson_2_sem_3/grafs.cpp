#include <iostream>
#include <vector>


class Graff {
private:
    std::vector <std::vector <bool>> matrix;
    int count_of_vertex = 0;

public:
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

};


class DFS_search {
private:
    std::vector <bool> pointed_list;
    int count_of_elems;

public:
    DFS_search(Graff graff){
        Graff graff = graff;
        pointed_list(graff.count_of_vertex);
        count_of_elems = graff.count_of_vertex;

    }


    void print_in_depth(int number_of_vertex) {
        if (pointed_list.at(number_of_vertex) == false) {
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


int main() {


}
