//
// Created by genius on 1/2/2023.
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
    int n, ans = 0;
    cin >> n;
    vector<int> want(n);
    vector<int> curt(n);
    vector<int> diff(n+2);
    diff[0] = 0;
    diff[n+1] = 0;
    for(int i = 0; i < n; i++){
        cin >> want[i];
    }
    for(int i = 0; i < n; i++){
        cin >> curt[i];
    }
    for(int i = 0; i < n; i++){
        diff[i+1] = want[i] - curt[i];
    }
    for(int i = 1; i <= n+1; i++){
        if(diff[i] > diff[i - 1]){
            int dif = diff[i] - diff[i-1];
            ans += dif;
        }
    }
    cout << ans;
}