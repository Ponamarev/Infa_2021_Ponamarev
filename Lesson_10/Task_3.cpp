#include <iostream>
#include <cstring>


int main() {
    int h;
    bool is_even = true;
    std::string letter;
    std::string arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
         'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    std::getline(std::cin, letter);

    for (int x = 0; x < letter.length(); x++) {
        h = arr.find(letter[x]);

        if (is_even) {
            if (h >= 26){
            }
            else {
                h = h + 26;
            }
        }
        else {
            if (h >= 26){
                h = h - 26;
            }
        }

        if (letter[x] != ' ') {
            letter[x] = arr[h];
            is_even = !(is_even);
        }
    }

    std::cout << letter;
    return 0;
}
