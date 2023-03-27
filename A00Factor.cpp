#include <bits/stdc++.h>

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
// N*Sqrt(N) = 1B = 10^9 for 1M numbers
int countFactors(int x) {
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if(i*i == x){
                ans++;
            }
            else{
                ans+=2;
            }
        }
    }
    return ans;
}

void print(vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// O(N*LogLogN + N*LogN) = 20M = 2*10^7 for 1M numbers
int countFactors2(int x) {

    // Time: O(N*LogLogN)
    // v:   2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    // gpf: 2 3 2 5 3 7 2 3  5 11  2 13  2  3  2 17  3 19  5
    vector<int> gpf(x + 1);
    for (int f = 2; f <= x; f++) {
        if (gpf[f] == 0) {
            for (int v = f; v <= x; v += f) {
                gpf[v] = f;
            }
        }
    }
    print(gpf);

    // Time: O(LogN)
    int ans = 1;
    while (x != 1) {
        int p = gpf[x];
        int count = 0;
        while (x % p == 0) {
            count++;
            x /= p;
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
