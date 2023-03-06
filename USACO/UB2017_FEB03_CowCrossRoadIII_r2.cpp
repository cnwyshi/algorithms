#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n, t = 0;
    cin >> n;
    vector<vector<int>> cow(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> cow[i][0] >> cow[i][1];
    }

    sort(cow.begin(), cow.end());
    for (vector<int>& c : cow) {
        t = max(t, c[0]) + c[1];
    }
    cout << t << "\n";
}