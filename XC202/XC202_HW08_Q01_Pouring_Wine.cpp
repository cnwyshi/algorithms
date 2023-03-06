#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a % 2 == 1){
        cout << -1 << endl;
    }
    vector<int> start = {a, b, c};
    queue<vector<int>> cups;
    cups.push(start);
    map<vector<int>, int> vis;
    vis[start] = 0;
    while(!cups.empty()){
        vector<int> cnt = cups.front();
        int x = cnt[0], y = cnt[1], z = cnt[2];
        cups.pop();
    }
}
/*
from position x to position y
int diff = x - y;
if(diff < 0){

 }
 */