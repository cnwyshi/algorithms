/*
nums = [1, 3, 5, 7, 9]
find the highest value less than or equal to 6
find the highest value less than or equal to 5
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);
    for(int i = 0; i < n; i++){
        cin >> trees[i];
    }
    //find highest possible = lowest impossible - 1
    long long lo = 0, hi = 10e9;
    while(lo < hi){
        int mid = (lo+hi)/2;
        long long sum = 0;
        for(int v: trees){
            sum += max(0, v-mid);
        }
        if(sum >= m){
            lo = mid +1;
        }
        else{
            hi = mid;
        }
    }
    cout << lo-1 << endl;
}
/*
Sample Input:
5 20
4 42 40 26 46
0 6  4  0  10
Sample Output:
36


*/