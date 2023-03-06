//
// Created by genius on 1/3/2023.
//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans;
        cin >> n;
        int mn = INT_MAX;
        vector<int> cows (n);
        for(int i = 0; i < n; i++){
            cin >> cows[i];
            mn = min(mn, cows[i]);
        }
        bool ok = false;
        for(int th = mn; th >= 0; th--){
            int steps = 0;
            vector<int> copy = cows;
            int i = 0;
            for(;i < n-1; i++) {
                int dif = copy[i] - th;
                if(dif < 0){
                    break;
                }
                steps += dif*2;
                copy[i] = th;
                copy[i + 1] -= dif;
            }
            if(i == n-1 && copy[n-1] == th){
                ok = true;
                cout << steps << endl;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
        }
    }
    return 0;
}
