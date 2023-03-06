#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(k%x == 0 && x > ans){
            ans = x;
        }
    }
    cout << k/ans;
}