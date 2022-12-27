#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> cost(n);
    for (int i = 0; i < n; i ++) {
        cin >> cost[i];
    }
    long ans = 0, f = 0;
    sort(cost.begin(), cost.end());
    for (int i = 0; i < n; i ++) {
        long c = cost[i] * (n - i);     // int * int = long long
        if (c > ans) {
            ans = c;
            f = cost[i];
        }
    }
    cout << ans << " " << f << endl;
    return 0;
}

/*
4
1 6 4 6
*/