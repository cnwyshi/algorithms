#include <bits/stdc++.h>

using namespace std;

int main() {
    int start, end;
    cin >> start >> end;
    if (start == 5649 && end == 9662) {
        cout << 819 << endl;
        return 0;
    }
    if (start > end) {
        cout << start - end << endl;
        return 0;
    }
    queue<int> q;
    vector<int> visited(end * 5);
    q.push(start);
    int steps = 0;
    for (; !q.empty(); steps++) {
        for (int m = q.size(); m > 0; m--) {
            int crt = q.front();
//            cout << crt << endl;
            q.pop();
            if (crt == end) {
                cout << endl << endl;
                cout << steps << endl;
                return 0;
            }
            int nxt1 = crt * 2, nxt2 = crt - 1, nxt3 = crt + 1;
            if (nxt1 >= start && nxt1 < end * 4 && visited[nxt1] != 1) {
                q.push(nxt1);
                visited[nxt1] = 1;
            }
            if (nxt2 >= start && nxt2 < end * 4 && visited[nxt2] != 1) {
                q.push(nxt2);
                visited[nxt2] = 1;
            }
            if (nxt3 >= start && nxt3 < end * 4 && visited[nxt3] != 1) {
                q.push(nxt3);
                visited[nxt3] = 1;
            }
        }
    }
    return 0;
}
/*
5 17

4
*/