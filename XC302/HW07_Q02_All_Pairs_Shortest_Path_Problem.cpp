#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > floyd_warshall(vector<vector<int> > ans, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int> > ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ans[i][j];
        }
    }
    ans = floyd_warshall(ans, n);
    for (int i = 0; i < n; i++) {
        if (ans[i][i] < 0) {
            cout << "No Solution";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}