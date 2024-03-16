#include <bits/stdc++.h>
using namespace std;
long long fibonacci(vector<long long>& memo, long long i){
    if(i <= 1){
        return 1;
    }
    if(memo[i] != -1){
        return memo[i];
    }
    else{
        cout << i << endl;
        return memo[i] = fibonacci(memo, i-1) + fibonacci(memo, i-2);
    }
}
int main(){
    int n;
    cin >> n;
    vector<long long> memo(n, -1);
    fibonacci(memo, n-1);
    cout << memo[n-1] << endl;
}












