#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t --) {
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> count(26);
        for (char c : s) {
            count[c - 'a'] ++;
        }
        for (int i = 0; i < k; i ++) {
            int c = n / k, j = 0;
            for ( ; c > 0 && count[j] > 0; j ++) {
                count[j] --;
                c --;
            }
            cout << (char)('a' + j);
        }
        cout << endl;
    }
    return 0;
}

/*
5
12 3
cabccadabaac
12 6
cabccadabaac
12 12
cabccadabaac
25 1
abcdefghijklmnopqrstuvwxy
10 5
bcdxedbcfg


*/