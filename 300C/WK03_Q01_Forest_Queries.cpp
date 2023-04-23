 #include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '*'){
                forest[i][j] = 1;
            }
            if(c == '.'){
                forest[i][j] = 0;
            }
        }
    }
    vector<vector<int>> ps(n, vector<int> (n));
    ps[0][0] = forest[0][0];

    for (int i = 1; i < n; i++){
        ps[0][i] = ps[0][i - 1] + forest[0][i];
    }
    for (int i = 1; i < n; i++){
        ps[i][0] = ps[i - 1][0] + forest[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++){
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + forest[i][j];
        }
    }
}
/*
8
-1 3 -2 5 3 -5 2 2
*/