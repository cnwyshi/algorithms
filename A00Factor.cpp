#include <iostream>
#include <vector>

using namespace std;

// Time: O(sqrt(N))
vector<int> primeFactor(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        ans.push_back(n);
    }
    return ans;
}

// Time: O(sqrt(N))
int countFactors(int x) {
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ans += i * i == x ? 1 : 2;
        }
    }
    return ans;
}

int countFactors2(int x) {

    // Time: O(N)?
    // v:   2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    // spf: 2 3 2 5 3 7 2 3  5 11  3 13  7  5  2 17  3 19  5
    vector<int> spf(x + 1);
    for (int i = 2; i <= x; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= x; j += i) {
                spf[j] = i;
            }
        }
    }

    // Time: O(LogN)
    int ans = 1;
    while (x != 1) {
        int prime = spf[x];
        int count = 0;
        while (x % prime == 0) {
            count++;
            x /= prime;
        }
        ans *= count + 1;
    }
    return ans;
}

int main() {
    for (int f: primeFactor(120)) {
        cout << f << " ";
    }
    cout << endl;
    cout << countFactors(20) << endl;
    cout << countFactors2(20) << endl;
}
