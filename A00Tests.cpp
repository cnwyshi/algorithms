#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> root, size;
    int count, max_value = 1;
public:
    DSU(int n) {
        count = n;
        root.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            root[i] = i;
        }
    }
    int find(int i) {
        return root[i] = (root[i] == i ? i : find(root[i]));
    }
    bool union_(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra == rb){
            return false;
        }
        root[ra] = rb;
        size[rb] += size[ra];
        max_value = max(max_value, size[rb]);
        count--;
        return true;
    }
};

int main() {
    int n;
    cin >> n;
}