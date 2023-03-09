#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0, ans = INT_MIN;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << ans;
}

/*
Sample input：
7
1 2 3 -5 4 3 -6


Sample output：
8

*/