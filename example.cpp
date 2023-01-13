#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    int nums[10] = {2 };
    // int nums[10] = { 1, 2 };
    for (int v : nums) {
        cout << v << " ";
    }
    vector<int> v(10);
    cout << abs((int)v.size()) << endl;

    // int a = 1000000000, b = 1000000000;
    ll a = 1000000000, b = 1000000000;
    ll c = a * b;
    cout << c << endl;
    // W: 10^18, LONG_LONG_MAX=2^63-1 =
    // 2^10 = 10^3
    // R: -2500
}

