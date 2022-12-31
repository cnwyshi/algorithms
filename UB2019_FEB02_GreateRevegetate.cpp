#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    ifstream  ifs("revegetate.in");
    ifs >> n >> m;

    int a[m], b[m], ans[n + 1];
    for (int i = 0; i < m; i ++) {
        ifs >> a[i] >> b[i];
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
    }

    ofstream  ofs("revegetate.out");
    for (int y = 1; y <= n; y ++) {
        int c = 0;
        for (c = 1; c <= 4; c ++) {
            bool match = true;
            for (int i = 0; i < m; i ++) {
                if (b[i] == y) {
                    int x = a[i];
                    if (ans[x] == c) {
                        match = false;
                    }
                }
            }
            if (match) {
                break;
            }
        }
        ans[y] = c;
        ofs << c;
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