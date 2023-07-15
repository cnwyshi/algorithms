#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> adj;
map<int, int> depth;
map<int, int> parent;

void get_depth(int node) {
    for (auto child: adj[node]) {
        depth[child] = depth[node] + 1;
        get_depth(child);
    }
}

int lca(int a, int b){
    if (depth[a] > depth[b]){
        swap(a, b);
    }
    while (depth[a] < depth[b]){
        b = parent[b];
    }

    while (a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;

}

int solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line );
        int parent_node;
        iss >> parent_node;
        string child;
        while (iss >> child){
            adj[parent_node].push_back(stoi(child));
            parent[stoi(child)] = parent_node;
        }
    }
    get_depth(1);
    cout << lca(a, b);

    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*
样例输入：
9 3 6
1 3 4 2
3 8 5
4 9 6 7


样例输出：
1
*/