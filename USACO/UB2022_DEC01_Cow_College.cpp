#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> tuition (n);
    for(int i = 0; i < n; i ++){
        cin >> tuition[i];
    }
    sort(tuition.begin(), tuition.end());
    ll ans = 0;
    int best_charge = 0;
    for(int i = 0; i < n; i++){
        ll cows = n-i;
        ll current = tuition[i] * cows;
        ll replace = ans;
        ans = max(current, ans);
        if(ans != replace){
            best_charge = tuition[i];
        }
    }
    cout << ans << " " << best_charge << endl;
}
/*
4
1 6 4 6
*/