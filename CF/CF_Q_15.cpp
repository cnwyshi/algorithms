#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
void solve(){
    map<string, bool> mp;
    int n;
    cin >> n;
    string str[n];
    for(int i = 0; i < n; i ++){
        cin >> str[i];
        mp[str[i]] ==true;
    }
    for(int i = 0; i < n; i ++){
        bool ok = false;
        for (int j = 1; j < str[i].length(); j++) {
            string pref = str[i].substr(0, j), suff = str[i].substr(j, str[i].length() - j);
            if (mp[pref] && mp[suff]) {ok = true;}
        }
        cout << ok;
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}