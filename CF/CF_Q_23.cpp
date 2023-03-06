#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        long long g[n][m];
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cin >> g[r][c];
            }
        }
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                long long sum = 0;
                for (int i = 1; r - i >= 0 and c - i >= 0; i++) {
                    sum += g[r - i][c - i];
                }
                for (int i = 1; r + i < n and c + i < m; i++) {
                    sum += g[r + i][c + i];
                }
                for (int i = 1; r + i < n and c - i >= 0; i++) {
                    sum += g[r + i][c - i];
                }
                for (int i = 1; r - i >= 0 and c + i < m; i++) {
                    sum += g[r - i][c + i];
                }
                sum += g[r][c];
                ans = max(ans, sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}