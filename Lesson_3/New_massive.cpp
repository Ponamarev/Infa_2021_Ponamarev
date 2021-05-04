#include <iostream>
using std::cin;
using std::cout;
using std::endl;
//У меня тесты работают и в первой задаче, и в этой. У них компилятор чего то жалуется...

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
    int* new_ptr_massive = nullptr;
    if (n_new != 0) {
        new_ptr_massive = new int[n_new];

        if (source != nullptr) {
            int n;
            if (n_old > n_new) {n = n_new;}
            else {n = n_old;}
            for (int i = 0; i < n; i++) {
                new_ptr_massive[i] = source[i];
            }

            delete[] source;
        }
    }


    return new_ptr_massive;
}


int main() {
    unsigned int n, i;
    cin >> n;
    int *a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
    for (i = 0; i < n / 2; i++)
        cin >> a[i];
    a = my_slightly_dumb_reallocation(a, n / 2, n);
    for (; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    cout << sum << endl;
    a = my_slightly_dumb_reallocation(a, n, n / 2);
    a = my_slightly_dumb_reallocation(a, n / 2, 0);
    a = my_slightly_dumb_reallocation(a, 0, 0);
    return 0;
}

