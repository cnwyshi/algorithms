//
// Created by genius on 11/14/22.
//
#include <iostream>
#include <fstream>

using namespace std;

void dfs(int n, int v, int &ans) {
    if (v > n) {
        return;
    }
    ans++;
    dfs(n, v * 10, ans);
    dfs(n, v * 10 + 1, ans);
}

int main() {
    int n, ans = 0;
    cin >> n;
    dfs(n, 1, ans);
    cout << ans << endl;
}
/*
10
2

n = 102 ans = 0;
v = 1 ans = 1; 10
 v = 10 ans = 2;
  v = 100
  v = 101
 v = 11
  v = 110
  v = 111
1 10 100
     101
  11 110
     111


*/