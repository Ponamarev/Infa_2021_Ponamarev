#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


class Data_id {
    public:

    int id;
    int scan_number = 1;
    float min_n_a = 3.4E38;
    float max_n_a = 0;
    float delta = max_n_a - min_n_a;


    Data_id(int id, float neyron): id(id){
        if (this->min_n_a > neyron) this->min_n_a = neyron;
        if (this->max_n_a < neyron) this->max_n_a = neyron;
    };

};


bool compare(Data_id id_1, Data_id id_2) {
    bool answer;
    if (id_1.delta < id_2.delta) {
        answer = true;
    }
    if (id_1.delta == id_2.delta) {
    if (id_1.id < id_2.id) {answer = true;}
    else {answer = false;}
    }
    if (id_1.delta > id_2.delta) {
        answer = false;
    }
    return answer;
}


int main () {
    int N, time, id;
    std::vector<Data_id> data_list;
    std::vector<int> answers;
    float a, s, u, f, n_a;

    std::cin >> N;

    for (int j = 0; j < N; j++) {
        std::cin >> time >> id >> a >> s >> u >> n_a >> f;
        bool finded_in_list = false;
        for (int i = 0; i < data_list.size(); i++) {
            if (id == data_list[i].id) {
                if (n_a < data_list[i].min_n_a) {data_list[i].min_n_a = n_a;}
                if (n_a > data_list[i].max_n_a) {data_list[i].max_n_a = n_a;}
                finded_in_list = true;
                data_list[i].scan_number++;
                data_list[i].delta = data_list[i].max_n_a - data_list[i].min_n_a;
            }
        }
        if (!finded_in_list) {
            Data_id new_data(id, n_a);
            data_list.push_back(new_data);
        }
    }

    std::vector <Data_id> suspects;

    for (int i = 0; i < data_list.size(); i++) {
        if (data_list[i].scan_number > 1) {
            suspects.push_back(data_list[i]);
        }
    }

    sort(suspects.begin(), suspects.end(), compare);

    int count;
    if (suspects.size() > 3) {count = 3;}
    else {count = suspects.size();}

    for (int i = 0; i < count; i++) {
        std::cout << suspects[i].id << " ";
    }

    return 0;}
