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
    int n, m, a, b;
    cin >> n >> m;
    vector<int> leader(n + 1), size(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        leader[i] = i;
    }
    for (int i = 0, g = n, l = 1; i < m; ++i) {
        cin >> a >> b;
        int rx = find(leader, a), ry = find(leader, b);
        if (rx != ry) {
            //x->rx, rx -> ry
            leader[rx] = ry;
            size[ry] += size[rx];
            l = max(l, size[ry]);
            g--;
        }
        cout << g << " " << l << endl;
    }
}
/*
Sample input:
5 3
1 2
1 3
4 5


Sample output:
4 2
3 3
2 3


5 3
1 2, 1-2 3 4 5 -> 4 2
1 3, 1-2-3 4 5 -> 3 3
4 5, 1-2-3 4-5 -> 2 3
*/