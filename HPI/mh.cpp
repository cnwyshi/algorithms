#include "stdio.h"
#include "iostream"

using namespace std;

int main() {
    int n, k[1000], i, sum = 0, a[1000], count[1000] = {0}, j = 0, l, b[1000];
    while (1) {
        cin >> n;
        cin >> k[j];
        if (n == 0 && k[j] == 0) break;
        for (i = 0; i <= k[j]; i++) cin >> a[i];
        for (i = 0; i <= k[j];) {
            if (a[i] > n) break;
            if (sum < n) {
                sum = a[i] + sum;
                if (sum == n) {
                    if (i < k[j]) count[j]++;
                    sum = 0;
                } else if (sum > n) {
                    sum = a[i];
                    count[j]++;
                }
                i++;
            }
        }
        sum = 0;
        b[j] = i;
        j++;
    }
    for (l = 0; l < j; l++) {
        if (b[l] <= k[l]) cout << "No Solution" << endl;
        else cout << count[l] << endl;
    }
    return 0;
}