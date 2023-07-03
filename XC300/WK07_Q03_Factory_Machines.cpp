#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
<<<<<<< HEAD
    int t, p;
    cin >> t >> p;
    int desired[p];
    multiset<int> price;
    for (int i = 0; i < t; ++i) {
        int pos;
        cin >> pos;
        price.insert(pos);
    }
    for (int i = 0; i < p; ++i) {
        cin >> desired[i];
    }
    for (int i: desired) {
        multiset<int>::iterator it = price.upper_bound(i);
        if (it == price.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            price.erase(it);
=======
    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for(int i = 0; i < n; ++i){
        cin >> k[i];
    }
    long long lo = 0;
    long long hi = 1e18;
    while(lo < hi){
        long long mid = (lo + hi)/2;
        long long products = 0;
        for(int i = 0; i < n && products < t; ++i){
            products+=mid/k[i];
        }
        if(products < t){
            lo = mid+1;
        }
        else{
            hi = mid;
>>>>>>> add XC302
        }
    }
    cout << lo << endl;
}
/*
Constraints
1≤n≤2⋅105
1≤t≤109
1≤ki≤109

n = 1000, t = 10000, ki = 1, ans = 10
n = 1000, t = 10000, ki = 1000, ans = 10000
ans = t/n*ki
*/