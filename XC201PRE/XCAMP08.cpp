#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v;
    for (int i = 0; i < (n + m); i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}
