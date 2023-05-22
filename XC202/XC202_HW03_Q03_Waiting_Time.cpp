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
    int n, k;
    cin >> n >> k;
    queue<int> l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.push(x);
    }
    int s = 0;
    while (!l.empty()) {
        s++;
        if (l.front() == 1) {
            if (k == 0) {
                cout << s << "\n";
                break;
            }
            l.pop();
        } else {
            int p = l.front() - 1;
            l.pop();
            l.push(p);
        }
        k--;
        if (k < 0) {
            k = (int) l.size() - 1;
        }
    }
    return 0;
}