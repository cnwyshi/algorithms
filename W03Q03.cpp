//
// Created by genius on 10/1/22.
//

#include <iostream>
#include <array>
#include <cmath>

using namespace std;
bool vis[11];
void permutations(int n,int m, array<int, 11>& a, int& ans) {
    if(m == n){
        bool match = true;
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << " ";
        // }
        //cout << endl;
        for(int i = 1; i<n; i++){
            if(abs(a[i] - a[i-1]) <=1){
                match = false;
                break;
            }
        }
        if( match){
            ans ++;
        }
        return;
    }
    else{
        for(int i = 1; i<=n; i++){
            if(vis[i] != 0) continue;
            vis[i] = 1;
            a[m] = i;
            permutations(n,m+1, a, ans);
            vis[i] = 0;
        }
    }
}


int main() {
    int n;
    int ans = 0;
    array<int, 11> a;
    cin >> n;
    permutations(n, 0, a, ans);
    cout << ans;
}