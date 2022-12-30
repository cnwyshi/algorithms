#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a[10] = { 2 };
    // int a[10] = { 1, 2 };
    for (int v : a) {
        cout << v << " ";
    }
    vector<int> v(10);
    cout << abs((int)v.size()) << endl;
}

