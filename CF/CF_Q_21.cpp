// Source: https://usaco.guide/general/io

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
    vector<int> digits;
    bool endinzero = true;
    while(n>0) {
        int y = n % 10;
        n = n / 10;
        if (y > 0) {
            endinzero = false;
        }
        if (!endinzero) {
            digits.push_back(y);
        }
    }
    vector<int> version2(digits.size());
    for(int i = 0; i < digits.size();i++){
        version2[i] = digits[i];
    }
    bool palindrome = true;
    reverse(digits.begin(), digits.end());
    for(int i = 0; i < digits.size(); i++){
        if(version2[i] != digits[i]){
            palindrome = false;
        }
    }
    if(palindrome == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
/*
20102000
20102
00020102
 */