#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int operations = 0;
        vector<int> index;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                index.push_back(i);
            }
        }
        for (int i = 0; i < index.size(); i++) {
            int left = index[i] > 0 ? index[i] - 1 : abs(index[i+1] - index[i]);
            int right = index[i] < n - 1 ? n - index[i] - 2 : abs(index[i] - index[i-1]);
            if (left < k || right < k) {
                operations++;
                index[i] = INT_MIN;
            }
        }
        cout << operations << endl;
    }
    return 0;
}
