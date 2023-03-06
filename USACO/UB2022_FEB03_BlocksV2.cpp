#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
bool perm(vector<vector<char>> blocks){
    string s;
    cin >> s;
    int n = s.size();
    do {
        bool good = true;
        for(int i = 0; i < n; i++){
            if(find(blocks[i].begin(), blocks[i].end(), s[i]) == blocks[i].end()){
                good = false;
            }
        }
        if(good){
            return true;
        }
    }while(next_permutation(blocks.begin(), blocks.end()));
    return false;
}
int main() {
    int t;
    cin >> t;
    vector<vector<char>> blocks(4, vector<char> (6));
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cin >> blocks[i][j];
        }
    }
    sort(blocks.begin(), blocks.end());
    for (int i = 0; i < t; i++) {
        bool b = perm(blocks);
        if(b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
/*
10
DDLGFL
LAUDJE
QOGROU
SXBCND
EGQC
DDYQ
FGLC
SAQ
JDGS
PZHV
EDQL
LDQN
WROF
DJOS

YES
NO
YES
YES
YES
NO
YES
YES
NO
YES

*/
