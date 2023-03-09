#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        bool prime = true;
        for(int x = 2; x*x <= i; x++){
            if(i % x == 0){
                prime = false;
            }
        }
        if(prime){
            cout << i << " ";
        }
    }
    cout << endl;
}