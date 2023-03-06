#include <iostream>
#include <fstream>
#include <array>

using namespace std;
int order = 0;
bool visited[11];

void permutations(int n, int k, int m, array<int, 11> &a) {

    if (m == n) {
        order++;
        if (order == k) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            return;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 0) continue;
            visited[i] = 1;
            a[m] = i;
            permutations(n, k, m + 1, a);
            visited[i] = 0;
        }
    }
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    array<int, 11> nums;
    permutations(n, k, 0, nums);
}