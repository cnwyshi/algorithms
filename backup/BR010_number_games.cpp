// Source: https://usaco.guide/general/io

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> letter(9);
    int ans = 0;
    for(int i = 0; i < 8; i ++){
        cin >> letter[i];
    }
    for(int i = 0; i < 8; i ++){
        if(int(letter[i] - 48) == 1){
            ans ++;
        }
    }
    cout << ans << endl;
}
