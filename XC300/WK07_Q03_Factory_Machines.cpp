#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, p;
    cin >> t >> p;
    int desired[p];
    multiset<int> price;
    for (int i = 0; i < t; ++i) {
        int pos;
        cin >> pos;
        price.insert(pos);
    }
    for (int i = 0; i < p; ++i) {
        cin >> desired[i];
    }
    for (int i: desired) {
        multiset<int>::iterator it = price.upper_bound(i);
        if (it == price.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            price.erase(it);
        }
    }
}
/*
5 3
5 3 7 8 5
4 8 3
3
8
-1
*/