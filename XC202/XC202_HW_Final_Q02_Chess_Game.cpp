#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> v;
unordered_map<string, int> v1;
int dir[4] = {1, -1, 4, -4};
string start = "", en = "";
int f = 0;
struct chess_board {
    string g;
    int moves;
};

void bfs() {
    queue<chess_board> s;
    queue<chess_board> s1;
    s.push({start, 0});
    s1.push({en, 0});
    chess_board b;
    while (!s.empty() || !s1.empty()) {
        b = s.front();
        s.pop();
        if (v.count(b.g) >= 1) {
            continue;
        }
        if (v1.count(b.g) == 1) {
            cout << b.moves + v1[b.g];
            break;
        }
        v[b.g] = b.moves;
        for (int i = 0; i < 16; i++) {
            if (b.g[i] == '0') {
                for (int a = 0; a < 4; a++) {
                    if (a == 0 && i % 4 == 3)continue;
                    if (a == 1 && i % 4 == 0)continue;
                    if (a == 2 && i > 11)continue;
                    if (a == 3 && i < 4)continue;
                    swap(b.g[i], b.g[i + dir[a]]);
                    s.push({b.g, b.moves + 1});
                    swap(b.g[i], b.g[i + dir[a]]);
                }
            }

        }
        //--------------------------------------------------
        b = s1.front();
        s1.pop();
        if (v1.count(b.g) >= 1) {
            continue;
        }
        if (v.count(b.g) == 1) {
            cout << b.moves + v[b.g];
            break;
        }
        v1[b.g] = b.moves;
        for (int i = 0; i < 16; i++) {
            if (b.g[i] == '0') {
                for (int a = 0; a < 4; a++) {
                    if (a == 0 && i % 4 == 3)continue;
                    if (a == 1 && i % 4 == 0)continue;
                    if (a == 2 && i > 11)continue;
                    if (a == 3 && i < 4)continue;
                    swap(b.g[i], b.g[i + dir[a]]);
                    s1.push({b.g, b.moves + 1});
                    swap(b.g[i], b.g[i + dir[a]]);
                }
            }
        }
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        string temp;
        cin >> temp;
        start += temp;
    }
    for (int i = 0; i < 4; i++) {
        string temp;
        cin >> temp;
        en += temp;
    }
    bfs();
}