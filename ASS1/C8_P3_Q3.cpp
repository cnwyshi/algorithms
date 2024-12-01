#include <bits/stdc++.h>
using namespace std;
void rec(vector<int>& nums, int i, long long sum, int& ans, int selected) {
    int n = nums.size();
    if(i == n) {
        ans = max(ans, selected);
        return;
    }
    bool of = false;
    int sum1 = sum;
    int num1 = nums[i];
    while(sum1 > 0 || num1 > 0) {
        int x = sum1 % 10;
        int y = num1 % 10;
        if(x + y >= 10) {
            of = true;
            break;
        }
        sum1 /= 10;
        num1 /= 10;
    }
    rec(nums, i + 1, sum, ans, selected);
    if(!of) {
        rec(nums, i + 1, sum + nums[i], ans, selected + 1);
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> weights (n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int ans = 1;
    rec(weights, 0, 0, ans, 0);
    cout << ans << endl;
}
/*
00000123
*/