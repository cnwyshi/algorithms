// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n%10 >= 5){
        int j = n/10;
        int k = j*10;
        int ans = k+10;
        cout << ans << endl;
    }
    else{
        int j = n/10;
        int k = j*10;
        cout << k << endl;
    }
}
