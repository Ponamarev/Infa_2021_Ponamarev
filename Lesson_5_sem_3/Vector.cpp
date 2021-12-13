#include <iostream>


template <class T>
class Vector {
public:
    T* values;
    int size = 0;

    Vector (unsigned int size): size(size) {
        values = new T[size];
        for (int i = 0; i < size; i++) {
            values[i] = 0;
        }
    }

    Vector operator+ (Vector v_2){
        int min_size;
        if (this->size > v_2.size) {
            min_size = v_2.size;
        }
        else {
            min_size = this->size;
        }

        for (int i = 0; i < min_size; i++) {

        }
        this -> values + v_2.values;
        return
    }
};


int main() {


    Vector <int> gdf(3);
}
