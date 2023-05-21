#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    map<int, int> count;
    long long ans = 0;
    for(int i = 0, j = 0; j < n; j++){
        count[nums[j]]++;
        while(count.size() > k){
            count[nums[i]]--;
            if(count[nums[i]] == 0){
                count.erase(nums[i]);
            }
            i++;
        }
        ans+=j-i+1;
//        cout << i << ","  << j << endl;
//        for (std::map<int,int>::iterator it=count.begin(); it!=count.end(); ++it){
//            cout << it->first << ":" << it->second << ", ";
//        }
//        cout << endl;
//        cout << ans << endl << endl;
    }
    cout << ans << '\n';
}
/*
5 1
1 1 1 2 2

100 3
3 2 3 4 3 3 4 2 3 1 4 4 1 3 4 4 3 1 3 1 4 2 2 3 4 3 2 1 1 1 4 1 1 2 2 1 3 2 4 3 1 3 4 2 1 3 2 2 2 1 4 4 1 4 3 3 3 1 2 1 2 3 1 2 4 3 1 2 4 3 1 4 3 2 1 4 3 4 1 2 3 3 2 2 2 4 4 4 3 2 2 3 4 2 4 2 4 3 1 1
0 1 2 3 4 5 6 7 8 9

Input:
5 2
1 2 3 1 1
A B C D E

A
B
C
D
E
AB
CD
DE
CDE
i = 0
j = 0 count = {1:1}, ans += 1
j = 1 count = {1:1, 2:1} ans += 2(j-i+1)
j = 2 count = {1:1, 2:1, 3:1}, count.size() = 3, i = 1, count = {2:1,3:1} ans += 2
j = 3 count = {1:1, 2:1, 3:1} count.size() = 3, i = 2, count = {1:1, 3:1} ans += 2
j = 4 count = {1:2, 3:1} ans += 3

 ans = 10
Output:
10
*/