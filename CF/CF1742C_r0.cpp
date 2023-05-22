#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <array>

using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int a[N], b[N];


void sol() {
    vector<string> s(8);
    int n = 8;

    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool fl = 1;
        for (int j = 0; j < n; ++j)
            if (s[j] == 'B' || s[j] == '.') {
                fl = 0;
                //break;
            }

        if (fl) {
            cout << s[0] << endl;
            return;
        }

    }
    cout << "B" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) sol();
    return 0;
}