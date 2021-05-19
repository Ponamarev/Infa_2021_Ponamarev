#include <iostream>


int main() {
    unsigned int number_of_pairs;
    std::cin >> number_of_pairs;

    int* massive_f = new int[number_of_pairs];
    int* massive_k = new int[number_of_pairs];

    int f;
    int k;

    bool answer = false;

    for (int i = 0; i < number_of_pairs; i++) {
        std::cin >> f >> k;
        massive_f[i] = f;
        massive_k[i] = k;
    }

    for (int x = 0; x < number_of_pairs; x++) {
        for (int y = 0; y < number_of_pairs; y++) {
            for (int z = 0; z < number_of_pairs; z++) {
                if (x != z && x!= y && y != z){
                    if (massive_f[x] == massive_f[y] + massive_f[z]) {
                        if (massive_k[x] == massive_k[y] + massive_k[z]) {
                            answer = true;
                        }
                    }
                }
            }

            if (answer) {
                break;
            }
        }
        if (answer) {
            break;
        }
    }

    if (answer) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

    delete[] massive_f;
    delete[] massive_k;

    return 0;
}
