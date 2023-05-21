#include <bits/stdc++.h>
using namespace std;
int upper_bound(vector<int>& nums, int t){
    int n = nums.size(), lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if(nums[mid] <= t){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    return lo;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    cout << upper_bound(nums, m)+1 << endl;
}

/*
*/