#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
char s[N]; int a[N];
int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int pos, last;
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[1]) { //找位置靠后秘
            pos = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[1]) { //第一头秘类奶
            last = i;
        }
    }
    int ans = 0;
    for (int i = 1; i < pos; i++) {
        if ((i == 1 && a[i] >= last) || a[i] >= pos)
            ans++;
        printf("%d", ans);
        return 0;
    }
}
//int main() {
//    int n;
//    string s;
//    cin >> n >> s;
//    vector<int> e(n);
//    for (int i = 0; i < n; i ++) {
//        cin >> e[i];
//    }
//
//
//}

/*
4
GHHG
2 4 3 4

SAMPLE OUTPUT:
1

SAMPLE INPUT:
3
GGH
2 3 3

SAMPLE OUTPUT:
2
*/