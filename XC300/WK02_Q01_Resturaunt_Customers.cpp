#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<int, int> time;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        time[a]++;
        time[b]--;
    }
    int ans = 0;
    int temp = 0;
    for(auto i : time){
        temp+=i.second;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
/*
8
-1 3 -2 5 3 -5 2 2
*/