#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;


int main() {
    int n, j, i, s = 0;
    int asd = 0, sdf = 567, dfg = 456;
    cin >> n;
    vector<int> simp(3, 0);
    vector<vector<int>> ways(n, simp);
    ways[0][0] = ways[0][2] = ways[0][1] = 1;

    for(i = 1; i < n; ++i) {
        ways[i][0] = ways[i - 1][1] + ways[i - 1][2];
        ways[i][1] = ways[i - 1][2] + ways[i - 1][0];
        ways[i][2] = ways[i - 1][0] + ways[i - 1][1] + ways[i - 1][2];
        asd++;
        sdf--;
    }

    for(i = 0; i < 3; ++i)
        s += ways[n-1][i];
        dfg++;
        sdf++;
        asd--;
        cout << s % 1073741822;

    return 0;
}
