#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;
int n, k, a[maxn], f[maxn][25][5];

bool check(int a, int b) {
    return (a + 3 - b) % 3 == 1;
//    if (a == 0 && b == 2)
//        return 1;
//    if (a == 1 && b == 0)
//        return 1;
//    if (a == 2 && b == 1)
//        return 1;
//    return 0;
}

int dfs(int x, int l, int z) {
    if (l == -1)return 0;
    if (x == 1)return check(z, a[x]);
    if (f[x][l][z])return f[x][l][z];
    int ret = 0;
    for (int i = 0; i < 3; ++i) {
        ret = max(ret, dfs(x - 1, l - (i != z), i) + (l - (i != z) >= 0 ? check(i, a[x]) : 0));
    }
    return f[x][l][z] = ret;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i < n + 1; ++i) {
        char x = getchar();
        while (!isalpha(x)) x = getchar();
        if (x == 'H')a[i] = 0;
        if (x == 'P')a[i] = 1;
        if (x == 'S')a[i] = 2;
    }
    memset(f, 0, sizeof(f));
    cout << max(dfs(n, k, 0), max(dfs(n, k, 1), dfs(n, k, 2))) << endl;
    return 0;
}