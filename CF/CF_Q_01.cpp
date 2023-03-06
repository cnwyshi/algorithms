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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        vector<int> tm(n);
        for (int i = 0; i < n; i++) {
            cin >> tm[i];
        }
        int prev = 0;
        int total_time = 0;
        for (int i = 0; i < n; i++) {
            total_time += (a[i] - prev + tm[i]);
            int staying_time = (b[i] - a[i] + 1) / 2;
            if (i < n - 1) {
                total_time += staying_time;
            }
            if (total_time < b[i] && i < n - 1) {
                total_time = b[i];
            }
            prev = b[i];
        }
        cout << total_time << '\n';
    }
    return 0;
}