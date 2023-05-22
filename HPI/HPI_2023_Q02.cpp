#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }
    int left = sum % m;
    sum -= left;
    int ans = 0;
    ans += sum / m;
    if (left != 0) {
        ans++;
    }
    cout << ans << endl;
}