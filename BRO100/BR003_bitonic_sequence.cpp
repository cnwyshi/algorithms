#include <iostream>
#include <vector>

using namespace std;
int main() {
    int  n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int i = 0, j = n-1;
    while(i <= j){
        cout << nums[j] << endl;
        j--;
//        cout << i << " " << j << endl;
        if(i < j){
            cout << nums[i] << endl;
            i++;
//            cout << i << " " << j << endl;
        }
    }
}
/*
5
10
-1
3
3
-9
 */