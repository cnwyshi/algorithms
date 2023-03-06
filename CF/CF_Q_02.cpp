//
// Created by genius on 12/26/2022.
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
int main() {
    int n;
    cin >> n;
    int redcount;
    int count;
    while(n--){
        char s[10][10];
        redcount = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cin >> s[i][j];
            }
        }
        for(int i = 0; i < 8; i ++){
            count = 0;
            for(int j = 0; j < 8; j ++){
                if(s[i][j] == 'R')
                    count ++;
            }
            if(count == 8)
                redcount = 1;
        }
        if(redcount ==1){
            cout << "R" << endl;
        }
        else{
            cout << "B" << endl;
        }
    }
}
