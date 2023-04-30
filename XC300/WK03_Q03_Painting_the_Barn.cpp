#include <bits/stdc++.h>
using namespace std;
int ps[1000][1001];
int main(){
    int n, k;
    cin >> n >> k;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = a; i < c; i++){
            ps[i][b]++;
            ps[i][d]--;
        }
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(ps[i][j] == k){
                ans++;
            }
            ps[i][j+1]+=ps[i][j];
        }
    }
    cout << ans << endl;
}
/*
3 2
1 1 5 5
4 4 7 6
3 3 8 7
*/