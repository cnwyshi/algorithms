#include <bits/stdc++.h>
using namespace std;
vector<int> transform(int m, vector<int>& nums){
    int n = nums.size();
    for(int j = 0; j < m; j++){
        vector<int> prev = nums;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                nums[i] = prev[i+1];
            }
            if(i == n-1){
                nums[i] = prev[i-1];
            }
            else{
                nums[i] = prev[i-1] + prev[i+1];
            }
        }
    }
    return nums;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> ans = transform(m, nums);
    for(int v : ans){
        cout << v << " ";
    }
    cout << endl;
}
