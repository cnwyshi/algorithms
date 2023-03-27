#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N;
        vector<string> canvas(N);
        for (int i = 0; i < N; i++) {
            cin >> canvas[i];
        }
        cin >> K;
        vector<string> stamp(K);
        for (int i = 0; i < K; i++) {
            cin >> stamp[i];
        }
        vector<string> ans(N, string(N, '.'));
        for (int x = 0; x <= N - K; x++) {
            for (int y = 0; y <= N - K; y++) {
                for (int rot = 0; rot < 4; rot++) {
                    bool doable = true;
                    for (int i = 0; i < K && doable; i++) {
                        for (int j = 0; j < K && doable; j++) {
                            if (canvas[x + i][y + j] == '.' && stamp[i][j] == '*') {
                                doable = false;
                            }
                        }
                    }
                    if (doable) {
                        for (int i = 0; i < K; i++) {
                            for (int j = 0; j < K; j++) {
                                if (stamp[i][j] == '*') {
                                    ans[x + i][y + j] = '*';
                                }
                            }
                        }
                    }
                    vector<string> rotate(K, string(K, '.'));
                    for (int i = 0; i < K; i++) {
                        for (int j = 0; j < K; j++) {
                            rotate[i][j] = stamp[K - 1 - j][i];
                        }
                    }
                    stamp = rotate;
                }
            }
        }
        int i = 0;
        for (; i < N && canvas[i] == ans[i]; i++) {
        }
        cout << (i == N ? "YES" : "NO") << endl;
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