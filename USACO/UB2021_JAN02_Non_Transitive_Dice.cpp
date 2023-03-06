//
// Created by genius on 1/3/2023.
//

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
bool beat(vector<int> a, vector<int> b){
    int x = 0, y = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i] > b[j]){
                x++;
            }
            if(b[j] > a[i]){
                y++;
            }
        }
    }
    if(x>y){
        return true;
    }
    else{
        return false;
    }
}
bool transitive(vector<int> a, vector<int> b, vector<int> c){
    return beat(a, b) && beat(b, c) && beat(c, a) || beat(b, a) && beat(c, b) && beat(a, c);
}
bool solve(vector<int> a, vector<int> b, vector<int> c){
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            for(int k = 1; k <= 10; k++){
                for(int m = 1; m <= 10; m++){
                    c[0] = i;
                    c[1] = j;
                    c[2] = k;
                    c[3] = m;
                    if(transitive(a, b, c)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> a(4), b(4), c(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3];
        if(solve(a, b, c)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
/*
1
4 5 6 7 2 4 5 10*/