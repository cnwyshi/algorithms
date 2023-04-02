//
// Created by genius on 4/2/23.
//
#include <iostream>
#include <algorithm>
using namespace std;
int _gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return _gcd(a-b, b);
    return _gcd(a, b-a);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int g = _gcd(a, b);
        g = _gcd(g, c);
        a = a/g;
        b = b/g;
        c = c/g;
        bool even = (a % 2 == 0 || b % 2 == 0);
        long long ans = 0;
        if(even){
            if(c % 2 == 0){
                ans = c-2;
            }
            else if(c%2 == 1){
                ans = c-1;
            }
        }
        else{
            if(c % 2 == 0){
                ans = c-1;
            }
            else if(c%2 == 1){
                ans = c-2;
            }
        }
        cout << ans*g << endl;
    }
    return 0;
}