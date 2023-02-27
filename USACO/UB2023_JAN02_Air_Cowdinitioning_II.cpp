#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<pair<int, int>> st;
vector<int> comfort;
vector<pair<int, int>> conditioners;
vector<int> money;
vector<int> power;
int ans = 1e9;
int check(string s){
    vector<int> cold(101);
    for (int i = 1; i <= 100; i++) { // iterate through all stalls
        for (int j = 0; j < conditioners.size(); j++) { // use the air conditioners
            if (s[j] == '1' && conditioners[j].first <= i && conditioners[j].second >= i) {
                // if you use the air conditioner and i is included in the range
                cold[i] += power[j]; // change the coldness
            }
        }
    }
    bool works = true; // does it work?
    for (int i = 0; i < st.size(); i++) {  // see if the stall temp meets requirements
        for (int j = st[i].first; j <= st[i].second; j++) { // iterate through the stall ranges
            if (cold[j] < comfort[i]){ // if temp is warmer than comfort
                works = false; // doesnt work
            }
        }
    }
    int price = 0; // add the prices
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1'){ // if you use AC
            price += money[i];// add the money to the price
        }
    }
    if (works){ // if it works
        return price; // return the price
    }
    return 1e9; // it doesn't work, so you want to not make answer change
}
void sub(string s, int m){
    if(s.size() == m){
        ans = min(ans, check(s));
        return;
    }
    sub(s+"1", m);
    sub(s+"0", m);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        st.push_back({s, t});
        comfort.push_back(c);
    }
    for (int i = 0; i < m; i++) {
        int a, b, p, c;
        cin >> a >> b >> p >> c;
        conditioners.push_back({a, b});
        power.push_back(p);
        money.push_back(c);
    }
    sub("", m);
    cout << ans << endl;
}
/*
2 4
1 5 2
7 9 3
2 9 2 3
1 6 2 8
1 2 4 2
6 9 1 5

10
 The first line of input contains N
 and M
.

The next N
 lines describe cows. The i
th of these lines contains si
, ti
, and ci
.

The next M
 lines describe air conditioners. The i
th of these lines contains ai, bi
, pi
, and mi
.
*/