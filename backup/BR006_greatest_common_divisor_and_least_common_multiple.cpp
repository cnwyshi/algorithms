// Source: https://usaco.guide/general/io

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << a*b/gcd(a, b) << endl;
}