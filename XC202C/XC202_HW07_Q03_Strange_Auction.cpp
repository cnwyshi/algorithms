#include <iostream>
#include <queue>
using namespace std;
int main(){
    int h, l, ans = 0;
    cin >> h >> l;
    int a, b;
    cin >> a >> b;
    queue<int> front, back;
    front.push(h);
    back.push(l);
    while(!front.empty()){
        int cnt = front.front();
        front.pop();
        int next = cnt - a;
        if(next == l){
            ans++;
        }
        else if(next > l) {
            front.push(next);
        }
        next = cnt - b;
        if(next == l){
            ans++;
        }
        else if(next > l){
            front.push(next);
        }
    }
    cout << ans << endl;
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