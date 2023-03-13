#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        vector<vector<vector<int>>> castle(a, vector<vector<int>>(b, vector<int>(c, 1)));
        for(int i = 0; i < a; i++){
            for(int  j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    cin >> castle[i][j][k];
                }
            }
        }
        for(int i = 0; i < a; i++){
            for(int  j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    cout << castle[i][j][k];
                }
            }
        }
    }
}