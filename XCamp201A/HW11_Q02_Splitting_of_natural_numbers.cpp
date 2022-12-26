#include <iostream>
#include <vector>

using namespace std;
int n;

void dfs(int index, vector<int> data, int sum) {
    if (sum == n) {
        cout << n << "=" << data[0];
        for (int i = 1; i < data.size(); i++) {
            cout << "+" << data[i];
        }
        cout << endl;
        return;
    }
    for (int i = index; i <= min(n - 1, n - sum); i++) {
        data.push_back(i);
        dfs(i, data, sum+i);
        data.pop_back();
    }
}
int main() {
    cin >> n;
    vector<int> data;
    dfs(1, data, 0);
}