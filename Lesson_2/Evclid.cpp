#include <iostream>


int main() {

    int FirstNumber, SecondNumber, param;

    std::cin >> FirstNumber >> SecondNumber;
    if (FirstNumber < SecondNumber) { param = FirstNumber; FirstNumber = SecondNumber; SecondNumber = param; }
    while(FirstNumber != SecondNumber) {
      param = FirstNumber % SecondNumber;
      if (param==0) break;
      FirstNumber = SecondNumber;
      SecondNumber = param;
    }
    std::cout <<  SecondNumber;


    return 0;
}
