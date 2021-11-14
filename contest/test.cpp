#include <iostream>
#include <vector>
#include <algorithm>


void show_vector(int num, std::vector<int> datas)
{
    for (int i = 0; i < datas.size() ; i++){
        std::cout << datas[i] << "  " << std::endl;}
}

int main() {
    std::vector <int> asd{1,2,3,4,5,6};
    show_vector(6, asd);
    asd.erase(asd.begin() +2);
    show_vector(5, asd);

}
