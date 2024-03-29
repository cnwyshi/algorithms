#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define start first
#define end second

int n, a, b, maxCover, covered;
vector<pair<int, int>> shift;
int numCover[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    cin >> n;
    shift.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        shift[i] = make_pair(a, b);
        for (int j = a; j < b; ++j) {
            ++numCover[j];
        }
    }
    for (pair<int, int> lifeguard: shift) {
        for (int t = lifeguard.start; t < lifeguard.end; ++t) {
            --numCover[t];
        }
        covered = 0;
        for (int t = 0; t < 1000; ++t) {
            if (numCover[t] > 0) {
                covered++;
            }
        }
        for (int t = lifeguard.start; t < lifeguard.end; ++t) {
            ++numCover[t];
        }
        maxCover = max(covered, maxCover);
    }
    cout << maxCover;
    return 0;
}