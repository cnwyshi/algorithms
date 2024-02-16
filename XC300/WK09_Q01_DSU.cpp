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
    int n, m, z, x, y;
    cin >> n >> m;
    vector<int> leader(n + 1);
    for (int i = 0; i < n; ++i) {
        leader[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> z >> x >> y;
        int rx = find(leader, x), ry = find(leader, y);
        if (z == 1) {
            if (rx != ry) {
                leader[rx] = ry;
            }
        } else {
            cout << (rx == ry ? 'Y' : 'N') << '\n';
        }
    }
}
/*
Sample input 1：

4 7

2 1 2

1 1 2

2 1 2

1 3 4

2 1 4

1 2 3

2 1 4


 Sample output 1：

N

Y

N



4 7

2 1 2, N
1 1 2, 1-2

2 1 2, Y

1 3 4, 1-2 3-4

2 1 4, N

1 2 3

2 1 4
*/