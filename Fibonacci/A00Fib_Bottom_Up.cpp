#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> fib(n, -1);
    if(n <= 2){
        cout << 1 << endl;
    }
    fib[0] = fib[1] = 1;
    for(int i = 2; i < n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[n-1] << endl;
}






