#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long sum = 0;
    vector<long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        sum += h[i];
    }

    long avg = sum / n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    return 0;
}

/*
4
2 1 4 5
1 2
2 3
2 4

1(2)-2(1)-3(4)
      \
      4(5)
1+2+4+5=12 / 4 = 3

*/