#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t -- > 0) {
        int n, m, found = 0;
        cin >> n >> m;
        int tile[n][2][2];
        for (int i = 0; i < n; i ++) {
            cin >> tile[i][0][0] >> tile[i][0][1] >> tile[i][1][0] >> tile[i][1][1];
            found |= m % 2 == 0 && tile[i][0][1] == tile[i][1][0];
        }
        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
6

3 4

1 2
5 6

5 7
7 4

8 9
9 8

2 5

1 1
1 1

2 2
2 2

1 100
10 10
10 10

1 2
4 5
8 4

2 2
1 1
1 1
1 2
3 4

1 2
1 1
1 1


*/