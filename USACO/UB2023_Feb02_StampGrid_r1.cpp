#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }
        cin >> K;
        vector<string> stamp(K);
        for (int i = 0; i < K; i++) {
            cin >> stamp[i];
        }
        vector<string> ans(N, string(N, '.'));
        for (int rot = 0; rot < 4; rot++) {
            for (int i = 0; i <= N - K; i++) {
                for (int j = 0; j <= N - K; j++) {
                    bool can_stamp = true;
                    for (int a = 0; a < K; a++) {
                        for (int b = 0; b < K; b++) {
                            if (grid[i+a][j+b] == '.' && stamp[a][b] == '*') {
                                can_stamp = false;
                                break;
                            }
                        }
                        if (!can_stamp) {
                            break;
                        }
                    }
                    if (can_stamp) {
                        for (int a = 0; a < K; a++) {
                            for (int b = 0; b < K; b++) {
                                if (stamp[a][b] == '*') {
                                    ans[i+a][j+b] = '*';
                                }
                            }
                        }
                    }
                }
            }
            vector<string> new_stamp(K, string(K, '.'));
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    new_stamp[i][j] = stamp[K-1-j][i];
                }
            }
            stamp = new_stamp;
        }
        bool success = true;
        for (int i = 0; i < N; i++) {
            if (grid[i] != ans[i]) {
                success = false;
                break;
            }
        }
        cout << (success ? "YES" : "NO") << endl;
    }
    return 0;
}


/*
4

2
**
*.
1
*

3
.**
.**
***
2
.*
**

3
...
.*.
...
3
.*.
...
...

3
**.
.**
..*
2
.*
*.



*/