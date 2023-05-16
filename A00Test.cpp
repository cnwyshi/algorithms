#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int P = 1000000007;

int norm1(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}

int main() {
//    cout << (int)2LL << endl;
    cout << norm1(2LL) << endl;
    cout << norm1(2) << endl;
}

/*
    set<vector<int>> s;
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 2, 3};
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout << s.size() << endl;
 */