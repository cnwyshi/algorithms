#include <iostream>
#include <vector>
using namespace std;
int knapsack(vector<int>& w, vector<int>& v, int W){
    int n = w.size();
    vector<vector<int>> dp(n+1, vector<int> (W+1));
    // 3402 * 12880 * 4 / 1000 = 175,271.04kb > 65,536kb
    for(int i = 1; i <= n; i++){ // number of items checked
        for(int j = 0; j <= W; j++){ // used weight
            int wi = w[i-1], vi = v[i-1];
            dp[i][j] = dp[i-1][j];
            if(j >= wi){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wi] + vi);
            }
        }
    }
    return dp[n][W];
}

/*
 4 * 5
 v = 1 3 4 6 7
     2 6 8 12 14
     4 12 16 24 28
     8 24 32 48 56

 */


int knapsack_v2(vector<int>& w, vector<int>& v, int W){
    int n = w.size();
    vector<int> dp(W+1);
    for(int i = 1; i <= n; i++){
        vector<int> prev = dp;
        int vi = v[i-1], wi = w[i-1];
        for(int j = wi; j <= W; j++) {
            dp[j] = max(dp[j], prev[j - wi] + vi);
        }
    }
    return dp[W];
}



int knapsack_v3(vector<int>& w, vector<int>& v, int W){
    int n = w.size();
    vector<int> dp(W+1);
    for(int i = 1; i <= n; i++){
        int vi = v[i-1], wi = w[i-1];
        for(int j = W; j >= wi; j--) {
            dp[j] = max(dp[j], dp[j - wi] + vi);
        }
    }
    return dp[W];
}
int main(){
    int n, W;
    cin >> n >> W;
    vector<int> v(n);
    vector<int> w(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i]; // input w and then v
    }
    cout << knapsack_v3(w, v, W) << endl;
}




/*
2 3
1 1
3 2
*/