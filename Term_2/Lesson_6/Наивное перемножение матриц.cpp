#include <iostream>


int** naive_algorithm1(int** matrix_1, int** matrix_2, int size) { // С указателем в выводе.
    /*
    Перемножает матрицу 1 на матрицу 1 по правилу перемножения матриц.
    */
    int** matrix_answer = new int*[size];

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            for (int z = 0; z < size; z++) {
                matrix_answer[x][y] = matrix_1[z][y] * matrix_2[x][z];
            }
        }
    }

    return matrix_answer;
}


int naive_algorithm2(int (&A)[n][n], int (&B)[n][n], int (&C)[n][n], int size) { //С указателем на входе;
    /*
    Перемножает матрицы по обычному правилу перемножения матриц.
    */

    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            for (int z = 0; z < size; z++) {
                C[x][y] = A[z][y] * B[x][z];
            }
        }
    }

    return 0;
}


int main() {
    int** matrix = new int*[11];


}
