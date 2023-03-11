//
// Created by genius on 3/8/2023.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    vector<vector<int>> ans(2, vector<int> (q));
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    for(int i = 0; i < q; i++){
        ans[i][0] = INT_MAX;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        map<int, int> t;
        for(int j = a; j <= b; j++) {
            t[nums[j]]++;
        }
        for(auto j = t.begin(); j != t.end(); j++){
            if(j -> second < ans[i][0] && j-> first < ans[i][1]){
                ans[i][0] = j -> first;
            }
        }
    }
    for(int i = 0; i < q; i++){
        cout << ans[i][0] << endl;
    }
}


