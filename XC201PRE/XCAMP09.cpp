#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    vector<int> v(m + n);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int a = s[i] - '0', b = t[j] - '0', c = a * b;
            v[i + j + 1] += c;
            v[i + j] += v[i + j + 1] / 10;
            v[i + j + 1] %= 10;
        }
    }
    string ans;
    for (int i = 0; i < m + n; i++) {
        if (v[i] == 0 && ans.empty()) {
            continue;
        }
        char c = (char) ('0' + v[i]);
        ans += c;
    }
    if (ans.empty()) {
        cout << "0";
    }
    cout << ans;
    return 0;
}