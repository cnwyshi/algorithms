#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &leader, int i) {
    if (leader[i] == i) {
        return i;
    } else {
        int j = leader[i];
        leader[i] = find(leader, j);
        return leader[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> leader(n);
    for (int i = 0; i < n; i++) {
        leader[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
//                cout << i << " and " << j << " are friends." << endl;
                int x = find(leader, i), y = find(leader, j);
                if (x != y) {
                    leader[x] = y;
                }
            }
        }
    }
    set<int> leaders;
    for (int i = 0; i < n; i++) {
        int l = find(leader, i);
        leaders.insert(l);
    }
    cout << leaders.size();
}
/*
3
1 1 0
1 1 1
0 1 1
*/