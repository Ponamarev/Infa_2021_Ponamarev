#include <stdio.h>
#include <cmath>


// For using this program, you need to write n - size of matrix;
const int n = 400; // size of matrix.
// Работает для всех чисел !!!!!


int naive_algorithm(int (&A)[n][n], int (&B)[n][n], int (&C)[n][n], int size_matrix) {
    /*
    Ïåðåìíîæàåò ìàòðèöû ïî îáû÷íîìó ïðàâèëó ïåðåìíîæåíèÿ ìàòðèö.
    */

    for (int x = 0; x < size_matrix; x++) {
        for (int y = 0; y < size_matrix; y++) {
            for (int z = 0; z < size_matrix; z++) {
                C[x][y] += A[z][y] * B[x][z];
            }
        }
    }

    return 0;
}


bool isPower2(int number) {
    /*
    Ïðîâåðÿåò, ÿâëÿåòñÿ ëè ÷èñëî ñòåïåíüþ äâîéêè;
    */
    bool answer = false;
    // Log2(number);
    int pow_min = log(number) / log(2);
    int step_number = pow(2, pow_min);

    for (int i = pow_min; i <= pow_min + 1; i++) {
        if (step_number == number) {
            answer = true;
        }
        step_number *= 2;
    }

    return answer;
}





int multi(int (&MA)[n][n], int (&MB)[n][n], int (&MC)[n][n]) {
    int p1 = MA[0][0] * (MB[0][1] - MB[1][1]);
    int p2 = (MA[0][0] + MA[0][1]) * MB[1][1];
    int p3 = (MA[1][0] + MA[1][1]) * MB[0][0];
    int p4 = MA[1][1] * (MB[1][0] - MB[0][0]);
    int p5 = (MA[0][0] + MA[1][1]) * (MB[0][0] + MB[1][1]);
    int p6 = (MA[0][1] - MA[1][1]) * (MB[1][0] - MB[1][1]);
    int p7 = (MA[1][0] - MA[0][0]) * (MB[0][0] + MB[0][1]);

    MC[0][0] = p5 + p4 - p2 + p6;
    MC[0][1] = p1 + p2;
    MC[1][0] = p3 + p4;
    MC[1][1] = p5 + p1 - p3 + p7;

    return 0;
}


int add(int (&AM)[n][n], int (&BM)[n][n], int (&CM)[n][n], int segment) {
    for (int i = 0; i < segment; i++) {
        for (int j = 0; j < segment; j++) {
            CM[i][j] = AM[i][j] + BM[i][j];
        }
    }

    return 0;
}


int sub(int (&AM1)[n][n], int (&BM1)[n][n], int (&CM1)[n][n], int seg) {
    for (int i = 0; i < seg; i++) {
        for (int j = 0; j < seg; j++) {
            CM1[i][j] = AM1[i][j] - BM1[i][j];
        }
    }

    return 0;
}


int strassen(int (&A)[n][n], int (&B)[n][n], int (&C)[n][n], int size_matrix) {
    /*
    Ïåðåìíîæàåò ìàòðèöû À è B; C -  óêàçàòåëü íà ìàòðèöó - ðåçóëüòàò ðàáîòû.
    */
    if (size_matrix <= 64 or size_matrix % 2 == 1) {
        naive_algorithm(A, B, C, size_matrix);
    }
    else {
        if (!(isPower2(size_matrix))) {
            unsigned int new_size = pow(2, log(size_matrix) / log(2) + 1);
            int a1[n][n];
            int b1[n][n];
            int c1[n][n];
        }
        int half = size_matrix / 2;

        if (half != 1) {
            int full = half * 2;
            int A11[n][n];
            int A12[n][n];
            int A21[n][n];
            int A22[n][n];

            int B11[n][n];
            int B12[n][n];
            int B21[n][n];
            int B22[n][n];

            int C11[n][n];
            int C12[n][n];
            int C21[n][n];
            int C22[n][n];
            int P1[n][n];
            int P2[n][n];
            int P3[n][n];
            int P4[n][n];
            int P5[n][n];
            int P6[n][n];
            int P7[n][n];

            int Result1[n][n];
            int Result2[n][n];

            for (int i = 0; i < half; i++) {
                for(int j = 0; j < full; j++)
                {
                    A11[i][j] = A[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = half; j < full; j++) {
                    A12[i][j - half] = A[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for(int j = 0; j < half; j++) {
                    A21[i - half][j] = A[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for(int j = half; j < full; j++) {
                    A22[i - half][j - half] = A[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = 0 ;j < half; j++) {
                    B11[i][j] = B[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = half; j < full; j++) {
                    B12[i][j - half] = B[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for(int j = 0; j < half; j++) {
                    B21[i - half][j] = A[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for(int j = half; j < full; j++) {
                    B22[i - half][j - half] = B[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = 0; j < half; j++) {
                    C11[i][j] = C[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = half; j < full; j++) {
                    C12[i][j - half] = C[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for(int j = 0; j < half; j++) {
                    C21[i - half][j] = C[i][j];
                }
            }

            for (int i = half; i < full; i++) {
                for (int j = half; j < full; j++) {
                    C22[i - half][j - half] = C[i][j];
                }
            }
    //
            sub(B12, B22, Result1, half);
            multi(A11, Result1, P1);

            add(A11, A12, Result1, half);
            strassen(Result1, B22, P2, half);

            add(A21, A22, Result1, half);
            strassen(Result1, B11, P3, half);

            sub(B21, B11, Result1, half);
            strassen(A22, Result1, P4, half);

            add(A11, A22, Result1, half);
            add(B11, B22, Result2, half);
            strassen(Result1, Result2, P5, half);

            sub(A12, A22, Result1, half);
            add(B21, B22, Result2, half);
            strassen(Result1, Result2, P6, half);

            sub(A21, A11, Result1, half);
            add(B11, B12, Result2, half);
            strassen(Result1, Result2, P7, half);
    //
            add(P1, P2, C12, half);

            add(P3, P4, C21, half);

            add(P5, P6, Result1, half);
            sub(P4, P2, Result2, half);
            add(Result1, Result2, C11, half);

            sub(P1, P3, Result1, half);
            add(P5, P7, Result2, half);
            add(Result1, Result2, C22, half);

            for (int i = 0; i < half; i++) {
                for (int j = 0; j < half; j++) {
                    C[i][j] = C11[i][j];
                }
            }

            for (int i = 0; i < half; i++) {
                for(int j = half; j < n; j++) {
                    C[i][j] = C12[i][j - half];
                }
            }

            for (int i = half; i < n; i++) {
                for(int j = 0; j < half; j++) {
                    C[i][j] = C21[i - half][j];
                }
            }

            for (int i = half; i < n; i++) {
                for(int j = half; j < n; j++) {
                    C[i][j] = C22[i - half][j - half];
                }
            }
        }

        else {
            multi(A, B, C);
        }

    }

    return 0;
}


int main() {
    int a[n][n];
    int b[n][n];
    int c[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
        }
    }

    naive_algorithm(a, b, c, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%-5d", c[i][j]);
        }

        printf("\n\n\n");
    }

    return 0;
}
