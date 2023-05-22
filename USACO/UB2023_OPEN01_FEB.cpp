#include <bits/stdc++.h>

using namespace std;
vector<int> ans;

void seq(int i, int f, string s, vector<int> &f_pos, vector<char> c) {
    if (i == f - 1) {
        vector<char> copy1 = c;
        for (int j: f_pos) {
            copy1[j] = s[j];
        }
        for (char j: copy1) {
            cout << j << " ";
        }
        cout << endl;
        if (find(copy1.begin(), copy1.end(), 'BB') == copy1.end() ||
            find(copy1.begin(), copy1.end(), 'EE') == copy1.end()) {
            return;
        } else {
            int nt1 = count(copy1.begin(), copy1.end(), 'BB');
            int nt2 = count(copy1.begin(), copy1.end(), 'EE');
            if (find(ans.begin(), ans.end(), nt1) == ans.end()) {
                ans.push_back(nt1);
            }
            if (find(ans.begin(), ans.end(), nt2) == ans.end()) {
                ans.push_back(nt2);
            }
        }
        return;
    }
    seq(i + 1, f, s + "B", f_pos, c);
    seq(i + 1, f, s + "E", f_pos, c);
}

int main() {
    int n, f = 0;
    cin >> n;
    vector<char> c(n);
    vector<int> f_pos;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 'F') {
            f_pos.push_back(i);
            f++;
        }
    }
    seq(0, f, "", f_pos, c);
    sort(ans.begin(), ans.end());
    for (int i: ans) {
        cout << i << endl;
    }
}

/*
SAMPLE INPUT:
3
MOMMOM
MMO
MOO
SAMPLE OUTPUT:
4
-1
0
*/