#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> order(n);

    for (int i = 1; i < n; i++) {
        int a; cin >> a;
        order[i] = a;
    }
    // count represents the first element.
    int count = 1;
    int ans[1000];
    ans[0] = count;

    while (true) {
        for (int i = 1	; i < n; i++) {
            // append the next element that follows the order.
            ans[i] = order[i] - ans[i - 1];
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            // all cows have to be in the range 1 - N.
            if (ans[i] <= 0 || ans[i] > n) {
                flag = true;
                break;
            }
        }

        if (unique(begin(ans), begin(ans) + n) != begin(ans) + n || flag) {
            // permutation invalid, try the next one.
            fill_n(begin(ans), n, 0);
            count++;
            ans[0] = count;
        } else {
            // permutation valid, print out the vector.
            for (int i = 0; i < n; i++) {
                if (i != n - 1) {
                    cout << ans[i] << " ";
                } else {
                    cout << ans[i];
                }
            }
            break;
        }
    }
}