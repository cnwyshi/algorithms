#include <bits/stdc++.h>
using namespace std;
void print(vector<long long>& v) {
    for (long long x : v) {
        cout << x << " ";
    }
    cout << endl;
}
void print(multiset<long long>& m) {
    for (long long x : m) {
        cout << x << " ";
    }
    cout << endl;
}
int main(){
//    freopen("/Users/genius/Downloads/sample\\ (47).in", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
//    cout << n << endl;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<long long> prefix(n+1);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i]+nums[i];
    }
//    print(prefix);
    long long ans = LONG_LONG_MIN;
    multiset<long long> m;
    for(int i = a; i <= n; i++){
//        cout << i << endl;
        if(i > b){
            m.erase(m.find(prefix[i-b-1]));
        }
//        cout << __LINE__ << endl;
        m.insert(prefix[i-a]);
//        cout << __LINE__ << endl;
//        print(m);
        ans = max(ans, prefix[i] - *m.begin());
//        cout << i << ": " << prefix[i] << " " << *m.begin() << " " << prefix[i] - *m.begin() << endl;
    }
    cout << ans << endl;
}
/*

10 7 7
-22 0 78 -48 94 68 -7 -73 8 62


0 -22 -22 56 8 102 170 163 90 98 160
7
0

 i = 7, m = {0}, w = prefix[7] - prefix[0] = 163
 i = 8, m = {0, -22},m.erase(prefix[i-b-1] w = prefix[8] - prefix[1] = 112;
Input:
8 1 2
-1 3 -2 5 3 -5 2 2
0 -1 2 0 5 8 3 5 7

i = 1 prefix[i] = -1 multiset.insert(prefix[i-1]) = {0}, prefix[i] - m.begin() = -1
i = 2 prefix[i] = 2 multiset.insert(prefix[i-1]) = {-1, 0}, prefix[i] - m.begin() = 3, multiset.erase(prefix[i-b]) = {-1}
i = 3 prefix[i] = 0 multiset.insert(prefix[i-1]) = {-1, 0, 2}, prefix[i] - m.begin() = 1
Output:
8
vector = [1, 2, 3, 4]
ps = [0, 1, 3, 6, 10]
 i = 1; j = 2 subarray_sum = prefix[j+1] - prefix[i] = 5
200000 145842 147414

10 7 7
-22 0 78 -48 94 68 -7 -73 8 62

-22 0 78 -48 94 68 -7 -73 8 62

 0 -22 -22 56 8 102 170 163 90 98 160
 160 - 8 = 152
8 1 2
-1 3 -2 5 3 -5 2 2

8
0 -1 2 0 5 8 3 5 7

i = a = 1 multiset.insert(prefix[i - a]) = {0} ans = max(ans, prefix[i] - multiset.begin()) = -1
i = 2 multiset.insert(prefix[i-a]) = {0, -1} ans = max(ans, prefix[i] - multiset.begin()) = 2 - (-1) = 3
i = 3 multiset.insert(prefix[i-a]) = {0, -1, 2} ans = max(ans, prefix[i] - multiset.begin() = 0 - (-1) = 1

4 1 2
1 2 3 4

0 1 3 6 10
i = 1 multiset.insert(prefix[i-a]) = {0} ans = max(ans, prefix[i] - multiset.begin()) = 1
i = 2 multiset.insert(prefix[i-a]) = {0, 1} ans = max(ans, prefix[i] - multiset.begin()) = 3
i = 3 multiset.insert(prefix[i-a]) = {0, 1, 3}
ans = max(ans, prefix[i] - multiset.begin()) = 6

7868190130M
*/