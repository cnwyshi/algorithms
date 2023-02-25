#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N];
signed main() {
    int n;
    cin >> n;
    string st;
    cin >> st;
    st = ' ' + st;
    int g = 0, h = 0, G = 0, H = 0;
    for (int i = 1; i < st.size(); i++) {
        if (st[i] == 'G' && !g)g = i;
        else if (st[i] == 'H' && !h)h = i;
    }
    for (int i = st.size() - 1; i >= 1; i--) {
        if (st[i] == 'G' && !G)G = i;
        else if (st[i] == 'H' && !H)H = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    char ch;
    int ans = 0;
    bool gg = 0, hh = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == 'G') {
            if (a[i] >= h && i <= h && a[h] >= H) {
                ans++;
                if (i == g)gg = 1;
            }
        }
        if (st[i] == 'H') {
            if (a[i] >= g && i <= g && a[g] >= G) {
                ans++;
                if (i == h)hh = 1;
            }
        }
    }
    if(a[g]>=G&&a[h]>=H&&!gg&&!hh)ans++;
    cout<<ans;
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