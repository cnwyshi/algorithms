#include <iostream>
using namespace std;

const int N = 5000005;
int turn[N] = {0, 1};
bool comp[N] = {false};
int maxp[4] = {2, 1, 2, 3};

int main() {
    for(int i = 2; i < N; i++) {
        if(!comp[i]) {
            for(int j = i; j < N; j += i) {
                comp[j] = true;
            }
            maxp[i % 4] = i;
        }
        turn[i] = (i - maxp[i % 4]) / 2 + 1;
    }

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = N, a;
        for(int i = 0; i < n; i++) {
            cin >> a;
            if(turn[a] / 2 < ans / 2) {
                ans = turn[a];
            }
        }
        cout << (ans & 1 ? "Farmer John" : "Farmer Nhoj") << endl;
    }
}

/*
1
1
9

5
1
4
1
9
2
2 3
2
7 10
3
4 9 4
*/