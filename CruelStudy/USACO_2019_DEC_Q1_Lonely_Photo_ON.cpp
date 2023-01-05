//
// Created by genius on 1/2/2023.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    ll count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        ll l = 0, r = 0, li = i-1, ri = i+1;
//        cout << s[li] << s[i] << endl;
        while(li >= 0 && s[li] != s[i]){
//            cout << s[li] << s[i];
            l++;
            li--;
        }
//        cout << s[ri] << s[i] << endl;
        while(ri < n && s[ri] != s[i]){
            r++;
            ri++;
        }
//        cout << l << r << endl;
        count += l*r + max(0LL, l-1) + max(0LL, r-1);
    }
    cout << count;
}
/*
HHGHH
HHGH
 HGH
 HGHH
HHGHH
HHG
  GHH


*/


