#include <bits/stdc++.h>

using namespace std;

/**
 * Return the sum of A and B.
 *
 * A: a non-negative integer
 * B: another non-negative integer
 */
int solve(vector<int> sides) {
    map<int, int> dict;
    for (int i: sides) {
        dict[i]++;
    }
    int ans = 0;
    int ans2 = 0;
    for (auto i: dict) {
        int copy = ans;
        ans = max(ans, i.first * i.second);
        if (ans > copy) {
            for (int j = 0; j < sides.size(); j++) {
                if (sides[j] == i.first) {
                    ans2 = j;
                }
            }
        }
    }
    return ans2;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<int> sides(n);
        for (int j = 0; j < n; j++) {
            cin >> sides[j];
        }
        cout << solve(sides) << '\n';
    }
}
