#include <iostream>


class Matrix2D {
private:
    bool inited = false;
    unsigned int x_size;
    unsigned int y_size;
    double* ptr_data;


public:
    Matrix2D(unsigned int x_sizee, unsigned int y_sizee) /*: x_size(x_sizee - 1), y_size(y_sizee - 1)*/ { // „то то сломалось!!!!!!!!!!!!!!!
        /*
        x_size х размер матрицы 2d начина€ с единицы.
        y_size y размер матрицы 2d начина€ с единицы.
        */
        x_size = x_sizee;
        y_size = y_sizee;

        if(not(inited)) {
            inited = true;
            ptr_data = new double[x_sizee * y_sizee];
            }
        }


    Matrix2D(unsigned int size) {
     /*
        size размер матрицы 2d начина€ с единицы.
    */
        Matrix2D(size, size);
    }


    double Matrix2D_search(int x_position, int y_position) {
        /*
        x_position, y_position - Ќачинаютс€ с нул€.
        */
        int number = y_position * x_size + x_position;

        return ptr_data[number];
        }


    void print_matrix2D() {
        /*
        ¬ыводит матрицу в консоль.
        */
        std::cout << y_size << std::endl;
        std::cout << x_size << std::endl;
        for(int y = 0; y < y_size; y++) {
            for(int x = 0; x < x_size; x++) {
                std::cout << "1";
                //printf("%-5d", ptr_data[y * x_size + x]);
                if(x == x_size - 1) {
                    std::cout << std::endl;
                }
                else {
                    std::cout << "   ";
                }
            }
        }
    }


    void fill_matrix2D(double number) {
    /*
    «аполн€ет матрицу числом number.
    */
    std::cout << y_size << std::endl;
    std::cout << x_size << std::endl;
    for (int i = 0; i < y_size * x_size; i++) {
        ptr_data[i] = number;
        }
    }


    ~Matrix2D() {  //ƒеструктор. “ут надо удал€ть все, что мусорно. !!!!!!!!!!!!!!!!!!!!!
        delete [] ptr_data;
        }
};


int main() {
    std::cout << "It is testing mode" << std::endl << "..." << std::endl;

    Matrix2D matrix(3);
    std::cout << "Created matrix2D" << std::endl;

    matrix.fill_matrix2D(3);
    std::cout << "Filling it up by '3'" << std::endl;

    matrix.print_matrix2D();
}
