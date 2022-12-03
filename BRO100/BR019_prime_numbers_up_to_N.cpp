// Source: https://usaco.guide/general/io


#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++){
        int factors = 0;
        for(int j = 1; j <= i;j++){
            if(i%j == 0){
                factors++;
            }
        }
        if(factors == 2){
            cout << i << " ";
        }
    }
}