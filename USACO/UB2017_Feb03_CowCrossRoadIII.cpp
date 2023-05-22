#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n, t = 0;
    cin >> n;

    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        // this cow was already waiting, add questioning time to current time.
        if (t > cows[i].first) {
            t += cows[i].second;
        } else {
            // the last cow finished before this one arrived,
            // set the current time to when this cow finishes.
            t = cows[i].first + cows[i].second;
        }
    }

    cout << t << "\n";
}