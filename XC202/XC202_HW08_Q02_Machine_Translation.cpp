#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, ans = 0;
    cin >> m >> n;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    vector<int> mem;
    for (int i = 0; i < n; i++) {
        int cnt = words[i];
        if (find(mem.begin(), mem.end(), cnt) != mem.end()) {
            continue;
        } else {
            ans++;
            if (mem.size() < m) {
                mem.push_back(cnt);
            } else if (mem.size() == m) {
                mem.erase(mem.begin());
                mem.push_back(cnt);
            }
        }
    }
    cout << ans << endl;
}
/*
3 7
1 2 1 5 4 4 1

5


*/