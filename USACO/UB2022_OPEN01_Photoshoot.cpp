#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n, ans = 0;
    char last;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i+=2){
        if(s[i] != s[i+1]){
            if(s[i] != last){
                ans += 1;
                last = s[i];
            }
        }
    }
    if(last == 'H'){
        ans -= 1;
    }
    cout << ans << endl;
}