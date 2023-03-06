#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> range(n, vector<int>(2));
    for (int i = 0; i < n; i ++) {
        cin >> range[i][0] >> range[i][1];
    }
    for (int i = 0; i < n; i ++) {
        int t = 0;
        vector<bool> r(1000);
        for (int j = 0; j < n; j ++) {
            if (i != j) {
                for (int k = range[j][0]; k < range[j][1]; k ++) {
                    r[k] = true;
                }
            }
        }
        for (int k = 0; k < 1000; k ++) {
            t += r[k];
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
