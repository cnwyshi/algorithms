// Source: https://usaco.guide/general/io

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100000][21][3];

/*
HPS
012
*/
int dfs(vector<int>& signs, int i, int c, int k){
    int n = signs.size();
    int ans = 0;
    if(i == n){
        return 0;
    }
    if(dp[i][k][c]){
        return dp[i][k][c];
    }
    if((c + 3 - signs[i])%3 == 1){
        ans = max(ans, dfs(signs, i+1, c, k)+1);
    }
    else{
        ans = max(ans, dfs(signs, i+1, c, k));
        if(k > 0){
            ans = max(ans, dfs(signs, i+1, (signs[i]+1)%3, k-1)+1);
        }
    }
    return dp[i][k][c] = ans;
}
int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> signs (n);
    for(int i = 0;i < n; i ++){
        char x;
        cin >> x;
        if(x == 'H'){
            signs[i] = 0;
        }
        if(x == 'P'){
            signs[i] = 1;
        }
        if(x == 'S'){
            signs[i] = 2;
        }
    }
    ans = max(dfs(signs, 0, 0, k), dfs(signs, 0, 1, k));
    ans = max(ans, dfs(signs, 0, 2, k));
    cout << ans << endl;
}
/*
You've probably heard of the "rock, paper, scissors" game. FJ's cows like to
play a similar game they call "hoof, cloth, scissors" ("hoof" is "rock", "cloth" is "paper").

The rules of the game are simple: both sides of the game count to 3 at the same time, and then make a handsign
 at the same time, representing "hoof", "scissors" or "cloth". "Hoof" beats "scissors", "scissors" beats "cloth",
  and "cloth" beats "hoof". For example, if the first cow gives a "hoof" and the second cow gives a "cloth",
   the second cow wins. Of course, a "draw" is also possible (if the two cows have the same handsigns).

FJ wants to play against his winning cow, Bessie. Bessie, as an expert, is able to predict FJ's handsigns.
 Unfortunately, as a cow, Bessie is also very lazy. In fact, she is only willing to change her handsign up
  to a fixed number of times to complete the game. For example, she may only want to change once, then he may
   "hoof" a few times and "cloth" the rest.

Given that Bessie can predict the handsigns FJ will make, and the maximum number of times
 she wants to change her handsign, find the maximum number of games she can win.


 5 1

P
P
H
P
S



4


1<=n<=100000, 0<=k<=20
*/