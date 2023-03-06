//
// Created by genius on 1/26/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, b, x, y, ans = 100;
    cin >> n >> b;
    vector<int> xx, yy;
    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        xx.push_back(x);
        yy.push_back(y);
        points.push_back({x, y});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a = xx[i] + 1, b = yy[j] + 1;
            int ul = 0, ur = 0, ll = 0, lr = 0;
            for (vector<int> p: points) {
                int x = p[0], y = p[1];
                if (x < a && y > b) {
                    ul++;
                }
                if (x > a && y > b) {
                    ur++;
                }
                if (x < a && y < b) {
                    ll++;
                }
                if (x > a && y < b) {
                    lr++;
                }
            }

            int mx = max(max(ul, ur), max(ll, lr));
            ans = min(ans, mx);

        }
    }
    cout << ans;
    return 0;
}