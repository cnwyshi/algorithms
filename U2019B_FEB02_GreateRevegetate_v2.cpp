#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n, m, a, b;
    ifstream  ifs("revegetate.in");
    ifs >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i ++) {
        ifs >> a >> b;
        graph[max(a, b) - 1].push_back(min(a, b) - 1);
    }

    vector<int> color(n);
    ofstream  ofs("revegetate.out");
    ofs << (color[0] = 1);
    for (int j = 1; j < n; j ++) {
        int c = 0;
        for (c = 1; c <= 4; c ++) {
            bool match = true;
            for (int i : graph[j]) {
                if (color[i] == c) {
                    match = false;
                    break;
                }
            }
            if (match) {
                break;
            }
        }
        ofs << (color[j] = c);
    }
    return 0;
}

/*
5 6
4 1
4 2
4 3
2 5
1 2
1 5
*/