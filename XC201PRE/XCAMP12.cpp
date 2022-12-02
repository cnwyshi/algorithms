#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int ans = 0;
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> sheds;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sheds.push_back(k);
    }
    sort(sheds.begin(), sheds.end());
    int lo = 1, hi = sheds[n - 1] - sheds[1] + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int last = sheds[0], cows = 1;
        for (int i = 1; i < n; i++) {
            if (sheds[i] - last >= mid) {
                cows++;
                last = sheds[i];
            }
        }
        if (cows < m) {
            hi = mid;
        } else {
            lo = mid + 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    return 0;
}