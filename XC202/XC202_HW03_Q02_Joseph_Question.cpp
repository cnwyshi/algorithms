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
queue<int> josephus;
vector<int> order;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        josephus.push(i);
    }
    int i = (m == 1) ? 0 : 1;
    while (order.size() < n) {
        if (i == 0) {
            order.push_back(josephus.front());
            josephus.pop();
        } else {
            josephus.push(josephus.front());
            josephus.pop();
        }
        i = (i + 1) % m;
    }
    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
}