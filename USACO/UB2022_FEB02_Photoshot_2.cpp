//
// Created by genius on 1/4/2023.
//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> start(n), end(n);
    vector<bool> visited(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }
    for (int i = n - 1, j = n - 1; i >= 0;) {
//        printf("%d %d %d\n", i, j, ans);
        if (visited[end[j]]) {
            j--;
        } else if (start[i] != end[j]) {
            visited[start[i]] = true;
            ans++;
            i--;
        } else if (start[i] == end[j]) {
            i--;
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
5
5 1 3 2 4
4 5 2 1 3

5
i
5 1 3 2 4
    j
4 5 2 1 3
T F T F F
ans = 1
v = {}
 */