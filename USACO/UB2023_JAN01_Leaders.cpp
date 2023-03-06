#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    int fg, fh, lg, lh;
    string breed;
    cin >> breed;
    vector<int> e(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        e[i] = x;
    }
    fg = breed.find("G");
    fh = breed.find("H");
    lg = breed.rfind("G");
    lh = breed.rfind("H");
    if(e[fg] >= lg){
        for(int i = 0; i < fg; i++){
            if(e[i] >= fg){
                ans++;
            }
        }
    }
    if(e[fh] >= lh){
        for(int i = 0; i < fh; i++){
            if(e[i] >= fh){
                ans++;
            }
        }
    }
    if((e[fg] >= lg && e[fh] >= lh) && (lg < fh || lh < lg)){
        ans++;
    }
    cout << ans << endl;
}
/*
3
GGH
2 3 3

2

H G G H H
2 4 4 3 4

H H G G G
1 3 4 4 4

 GGHH
 HHGG



*/