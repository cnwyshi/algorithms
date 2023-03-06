#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

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
    map<string, int> front, back;
    queue<string> q1, q2;
    q1.push(board);
    q2.push(target);
    front[board] = back[target] = 0;
    while (!q1.empty() || !q2.empty()) {
        string s = q1.front();
        q1.pop();
        if (back.find(s) != back.end()) {
            cout << front[s] + back[s] << endl;
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
            // cout << s << " -> " << t << " " << front[t] << endl;
        }
        s = q2.front();
        q2.pop();
        if (front.find(s) != front.end()) {
            cout << front[s] + back[s] << endl;
            return 0;
        }
        i = s.find('0');
        for (int j : move[i]) {
            string t = s;
            swap(t[i], t[j]);
            if (back.find(t) == back.end()) {
                q2.push(t);
                back[t] = back[s] + 1;
            }
            // cout << t << " <- " << s << " " << back[t] << endl;
        }
    }
    cout << -1 << endl;
    return 0;
}

/*
283104765
123804765

 */