#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    map<vector<int>, int> m;
    vector<int> v = {1, 2}, u = {1, 2};
    m[v] = 2;
    cout << m[u] << endl;

    return 0;
}

/*
SAMPLE INPUT:
3 2
3 2 5
6 1
SAMPLE OUTPUT:
7
2
7
*/