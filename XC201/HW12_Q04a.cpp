#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void dfs(int n, int curr, int i, int s, vector<string> &ops) {
    if (i == n) {
        if (s == 0) {
            for (int j = 0; j < n; j++) {
                cout << (j + 1) << ops[j];
            }
            cout << endl;
        }
        return;
    }
    ops[i] = "+";
    // TODO-Fix
    dfs(n, curr, i + 1, s, ops);
    ops[i] = "-";
    dfs(n, curr, i + 1, s, ops);
    ops[i] = "";
    dfs(n, curr, i + 1, s, ops);
}

int main() {
    int n;
    cin >> n;
    vector<string> ops(n);
    dfs(n, 0, 0, 0, ops);
    return 0;
}

/*
n = 7
1+2+3

i = 0, s = 0 -> s = 1

i = 1, p = 1
  i = 2
      1 + 2
      1 - 2
      12

      1-3
dfs(1)
 1
 - s*10-i
 +

*/