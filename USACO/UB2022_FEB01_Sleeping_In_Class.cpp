//
// Created by genius on 1/4/2023.
//

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n = 0, ans = INT_MAX;
        cin >> n;
        vector<int> sleep(n);
        int mx = 0, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> sleep[i];
            mx = max(mx, sleep[i]);
            sum += sleep[i];
        }
        if(mx*n == sum){
            cout << 0 << endl;
            continue;
        }
        for(int a = mx; a <= sum; a++){
            if(sum % a != 0){
                continue;
            }
            int j = 0, tempsum = 0;
            for(; j<n; j++){
                tempsum += sleep[j];
                if(tempsum == a){
                    tempsum = 0;
                }
                if(tempsum > a){
                    break;
                }
            }
            if(j == n && tempsum == 0){
                cout << n-sum/a << endl;
                break;
            }
        }
    }
}
/*
3
6
1 2 3 1 1 1
3
2 2 3
5
0 0 0 0 0
 */