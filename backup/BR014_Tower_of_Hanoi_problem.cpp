#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// a = 1, c = 3
// 1 3
//
/*
n = 3

1
2
3
- - -
a b c

  1
3 2
- - -
a b c

  1
  2 3
- - -
a b c


- - -
a b c

n = 1
1
- - -
a b c
*/

int tower_of_hanoi(int n, vector<string> &steps, string a, string b, string c) {
    if (n == 1) {
        steps.push_back(a + "->" + c);
        return 1;
    } else {
        int count = 0;
        count += tower_of_hanoi(n - 1, steps, a, c, b);
        steps.push_back(a + "->" + c);
        count++;
        count += tower_of_hanoi(n - 1, steps, b, a, c);
        return count;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> steps;
    int count = tower_of_hanoi(n, steps, "1", "2", "3");
    for (int i = 0; i < steps.size(); i++) {
        cout << steps[i] << endl;
    }
    cout << "tot=" << count << endl;
    return 0;

}

