#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

const int WIDTH = 3;

vector<string> board(WIDTH);
set<set<char>> winners[WIDTH + 1];

void insert(vector<pair<int, int>> coordinates) {
    set<char> contained;
    for (const pair<int, int>& p: coordinates) {
        contained.insert(board[p.first][p.second]);
    }
    // add the amount of cows who contributed to this to the winners count
    winners[contained.size()].insert(contained);
}

int main() {
    ifstream read("tttt.in");
    for (int r = 0; r < WIDTH; r++) {
        read >> board[r];
    }
    // insert rows
    for (int i = 0; i < WIDTH; i++) {
        insert({{i, 0}, {i, 1}, {i, 2}});
    }
    // insert columns
    for (int i = 0; i < WIDTH; i++) {
        insert({{0, i}, {1, i}, {2, i}});
    }
    // insert the 2 diagonals
    insert({{0, 0}, {1, 1}, {2, 2}});
    insert({{2, 0}, {1, 1}, {0, 2}});

    ofstream written("tttt.out");
    written << winners[1].size() << endl;
    written << winners[2].size() << endl;
}