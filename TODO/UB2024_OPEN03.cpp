#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t, n;
    cin >> t;
    while (t --) {
        cin >> n;
        set<int> s;
        vector<int> p(n), h(n-1);
        for (int& v : h) {
            cin >> v;
            s.insert(v);
        }

    }
    return 0;
}

/*

 2 1 1
 [_, 2, _, _]
 [4, 2, _, _]

输入样例：
5
2
1
2
2
4
1 1 1
4
2 1 1
4
3 2 1
输出样例：
1 2
-1
-1
3 1 2 4
1 2 3 4

*/