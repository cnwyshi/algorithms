#include <bits/stdc++.h>
using namespace std;

// lie -> liars


int main() {
    int n, ans = INT_MAX;
    cin >> n;
    vector<char> c(n);
    vector<int> v(n);
    for (int i = 0; i < n; i ++) {
        cin >> c[i] >> v[i];
    }

    for (int i = 0; i < n; i ++) {
        int liars = 0;
        for (int j = 0; j < n; j ++) {
            liars += c[j] == 'G' ? v[i] < v[j] : v[i] > v[j];
        }
        ans = min(ans, liars);
    }
    cout << ans << endl;
    return 0;
}

/*
2
G 2
L 1

N = 1000, P = O(10^9)
Time: O(NP)

p = 3, N,
p = 4
p = 5

2
G 3
L 5 -> 0 (4)

discrete math, group theory, V E
algebra, continous, 1 1.25 1.5 2

discretization

p = 1             -> 1
p = 1000          -> 2
p = 1000000       -> 3
p = 1000000000    -> 4


L 1
G 1000
L 1000000
G 1000000000

 ---------------------------------------->
   1    1000  10000000  1000000000
   index = { 1: 1, 1000: 2, 1M : 3, 1B: 4 }
 ------------------------>
   1    2    3    4

L 1
G 2
L 3
G 4

L 500
G 200
L 1000
G 30

 ----------------------->
  30 200 500 1000

L 3
G 2
L 4
G 3

L 10
G 10
L 20
G 10



*/