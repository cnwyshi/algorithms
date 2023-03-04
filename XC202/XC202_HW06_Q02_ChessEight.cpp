#include <bits/stdc++.h>
using namespace std;

/*
012
345
678
*/
int main() {
    vector<vector<int>> move = {{1, 3},{0, 2, 4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7}};
    string board, target = "123804765";
    cin >> board;
    map<string, int> front;
    queue<string> q1;
    q1.push(board);
    front[board] = 0;
    while (!q1.empty()) {
        string s = q1.front();
        q1.pop();
        if (s == target) {
            cout << front[s] << endl;
            return 0;
        }
        int i = s.find('0');
        for (int j : move[i]) {
            string t = s;
            swap(t[i], t[j]);
            if (front.find(t) == front.end()) {
                q1.push(t);
                front[t] = front[s] + 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

/*
283104765
123804765

 */