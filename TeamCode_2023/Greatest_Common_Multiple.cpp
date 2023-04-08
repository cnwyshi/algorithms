#include <bits/stdc++.h>
using namespace std;

int _gcd(int a, int b){
    if (a == 0)
        return b;
    return _gcd(b % a, a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, c;
        cin >> a >> b >> c;
        long long g = _gcd(a,b);
        long long lcm = a*b/g;
        g = _gcd(g,c);
        a = a/g;
        b = b/g;
        c = c/g;
        long long ans = 0;
        long long left = lcm%c;
        ans = lcm-left;
        cout << ans << endl;
    }
    return 0;
}