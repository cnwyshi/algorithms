#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main() {
    string board;
    cin >> board;
//    vector<vector<int>> board(3, vector<int> (3));
    map<string, int> front, back;
    front[board] = 0; // empty space
    back["123804765"] = 0;
    queue<string> q1, q2;
    vector<vector<int>> move = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};
    q1.push(board);
    q2.push("123804765");
    while(!q1.empty() && !q2.empty()){
        string s = q1.front();
        q1.pop();
        if(back.find(s) != back.end()){
            cout << front[s]+back[s] << endl;
            return 0;
        }
        int i = s.find('0');
        for(int j: move[i]){
            string t = s;
            swap(t[i], t[j]);
            if(front.find(t) == front.end()){
                q1.push(t);
                front[t] = front[s]+1;
            }
        }
        s = q2.front();
        q2.pop();
        if(front.find(s) != front.end()){
            cout << front[s]+back[s] << endl;
            return 0;
        }
        i = s.find('0');
        for(int j: move[i]){
            string t = s;
            swap(t[i], t[j]);
            if(back.find(t) == back.end()){
                q2.push(t);
                back[t] = back[s]+1;
            }
        }
    }
}
/*
283
104
765

203
184
765

0 1 2
3 4 5
6 7 8

283104765 4
1 3 5 8
1 3

123
804
765
*/