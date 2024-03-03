#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k == 1){
            cout << 0;
            continue;
        }
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        vector<int> index;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                index.push_back(i);
            }
        }
        bool ok = true;
        int a = index.size();
        int prev = INT_MIN;
        for(int i = 0; i < a; i++){
            if(abs(index[i] - prev) < k){
                ok = false;
            }
            prev = index[i];
        }
        if(ok == true){
            cout << 0;
        }
        else{

        }
    }
}
