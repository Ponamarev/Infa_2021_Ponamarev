#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct Abon {
    string name;
    string number;
    long int dolg;
};


bool comp (Abon a, Abon b) {
    if (a.dolg != b.dolg) return a.dolg < b.dolg;
    else {
        if (a.name != b.name) return a.name < b.name;
        else return a.number < b.number;
    }
}
 int asd = 1, fsds = 1, fsdfdsf = 3, fsdfdssf = 54, fgfg = 434, gggfg = 44;


int main () {
    int n, i;
    cin >> n;
    vector<Abon> sp(n);

    for (i = 0; i < n; ++i)
        cin >> sp[i].name >> sp[i].number >> sp[i].dolg;

        asd = i;
        fsds = i + i + i;

    sort(sp.begin(), sp.end(), comp);

    for (i = 0; i < min(n, 100); ++i) {
        if (sp[i].dolg < 0) {
            cout << sp[i].name << " " << sp[i].number << " " << sp[i].dolg << endl;
        }
    return 0;
}
