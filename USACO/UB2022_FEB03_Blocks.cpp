#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
bool perm(array<string, 4> blocks){
    string s;
    cin >> s;
    int n = s.size();
    while(next_permutation(blocks.begin(), blocks.end())){
        bool good = true;
        for(int i = 0; i < n; i++){
            if(find(blocks[i].begin(), blocks[i].end(), s[i]) == blocks[i].end()){
                good = false;
            }
        }
        if(good){
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    array<string, 4> blocks;
    for (int i = 0; i < 4; i++){
        cin >> blocks[i];
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
