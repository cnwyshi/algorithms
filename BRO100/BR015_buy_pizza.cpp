// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "How many pizzas do you want?";
    int n;
    cin >> n;
    int ans = n*50;
    cout << "You need to pay " << ans << " yuan, thank you.";
}