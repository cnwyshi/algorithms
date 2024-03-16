#include <bits/stdc++.h>
using namespace std;
long long fibonacci(long long i){
    if(i <= 2){
        return 1;
    }
    else{
        cout << i << endl;
        return fibonacci(i-1) + fibonacci(i-2);
    }
}
int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}









