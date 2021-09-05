#include <iostream>


struct Element {
    int asd = 0;
    double sdf = 123456789;
};


Element* create_one_new() {
    Element* ptr = new Element();
    return ptr;
}


int main() {
    Element elem = {1, 2};
    Element elem2;
    Element elem1 = {};
    elem1.asd = 1234567;

    Element* gfd = new Element[234];
    gfd[0].asd = 23456789;
    std::cout << gfd[0].asd;

    delete[] gfd;
}
