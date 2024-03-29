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
    int N;
    cin >> N;
    vector<int> p(N + 1), t(N + 1), d(N + 2);
    for (int i = 1; i <= N; ++i)
        cin >> p[i];
    for (int i = 1; i <= N; ++i)
        cin >> t[i];
    for (int i = 1; i <= N; ++i)
        d[i] = p[i] - t[i];
    int ans = 0;
    for (int i = 0; i <= N; ++i)
        ans += abs(d[i] - d[i + 1]);
    cout << ans / 2;
}

/*
5
1 5 3 3 4
1 2 2 2 1

100
23 60 9 48 39 40 97 69 84 35 44 25 11 83 8 61 83 12 27 100 34 0 35 10 10 96 39 87 53 5 40 42 66 15 90 71 55 87 39 5 88 49 97 100 32 4 60 81 83 53 80 16 53 14 94 29 77 99 16 29 3 22 71 35 4 61 6 25 13 11 30 0 27 94 66 25 64 92 5 47 44 85 29 63 65 89 59 41 87 41 36 57 29 7 92 33 34 64 59 47
76 55 13 2 48 46 27 12 37 99 25 48 83 20 77 13 9 35 55 62 76 57 18 72 64 10 4 64 74 63 77 15 18 91 84 32 36 77 10 39 75 35 87 23 22 30 37 31 65 58 59 7 14 78 79 45 54 83 8 94 12 86 9 97 42 93 95 44 70 5 83 10 40 36 34 62 66 71 59 97 95 18 3 8 62 48 19 15 98 28 8 9 80 84 72 21 43 66 65 79

*/