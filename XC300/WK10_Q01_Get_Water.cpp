#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("C:\\Users\\flame\\Downloads\\sample-54.in", "r", stdin);
    int n;
    cin >> n;
    map<int, int> time;
    vector<int> time2;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        time2.push_back(t);
        time[t] = i;
    }
    sort(time2.begin(), time2.end());
    double sum = 0;
    for (int v: time2) {
        cout << time[v] << " ";
    }
    for (int i = n - 1; i >= 0; i--) {
        sum += i * time2[n - i - 1];
    }
    cout << endl;
    double mean = sum / n;
    cout << fixed << setprecision(2) << mean << '\n';
}
/*
10
56 12 1 99 1000 234 33 55 99 812

3 2 7 8 1 9 9 6 10 5
3 2 7 8 1 4 9 6 10 5
*/