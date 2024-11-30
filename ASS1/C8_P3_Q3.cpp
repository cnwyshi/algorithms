#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> weights (20);
vector<int> convert(int num) {
    vector<int> digits;
    bool endinzero = true;
    while (num > 0) {
        int y = num % 10;
        num = num / 10;
        if (y > 0) {
            endinzero = false;
        }
        if (!endinzero) {
            digits.push_back(y);
        }
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int main(){
    cin>>n;
    for(int i = 0; i < n; i++){

    }

}
/*
long long max about 2^63-1 =
*/