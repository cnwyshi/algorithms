#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
using namespace std;
int dfs(int current, int& l, int& a, int& b, map<int, int>& mem){
    if(current < l){
        return 0;
    }
    if(current == l){
        return 1;
    }
    if(mem[current] != 0){
        return mem[current];
    }
    mem[current] = dfs(current - a, l, a, b, mem) + dfs(current - b, l, a, b, mem);
    return mem[current];
}
int main(){
    int h, l;
    cin >> h >> l;
    int a, b;
    cin >> a >> b;
    map<int, int> mem;
    cout << dfs(h, l, a, b, mem) << endl;
}
/*
10 - 3 = 7
0 1 2 3 4 5 6 7
1   1 1 1 2 2 3

10 3
q1: 8, 7
vis1[10] = 1;
vis1[8] = 1;
vis1[7] = 1;
vis1[6] = 1;
vis1[5] = 1;
vis1[5] = 2; ans+=1*1
q2: 5, 6
vis2[3] = 1;
vis2[5] = 1;
vis2[6] = 1;
vis[
*/