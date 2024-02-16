#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18, MOD = 1e9 + 7;
static const auto fast = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<vector<int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    vector<ll> dist(n + 1, inf), count(n + 1), mi(n + 1, inf), mx(n + 1);

    count[1] = 1;
    mi[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        vector<ll> top = pq.top();
        pq.pop();
        ll d = top[0], i = top[1];
        for (vector<int> next: adj[i]) {
            int j = next[0], w = next[1];
            if (d + w < dist[j]) {
                dist[j] = d + w;
                pq.push({dist[j], j});
                count[j] = count[i];
                mi[j] = mi[i] + 1;
                mx[j] = mx[i] + 1;
            } else if (d + w == dist[j]) {
                count[j] = (count[j] + count[i]) % MOD;
                mi[j] = min(mi[j], mi[i] + 1);
                mx[j] = max(mx[j], mx[i] + 1);
            }
        }
    }
    cout << dist[n] << " " << count[n] << " " << mi[n] << " " << mx[n];
    return 0;
}


/*
C.  Investigation
Problem ID: 14072
Contest ID: 5676
必做题
Accepted
100 分
Description

You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:

what is the minimum price of such a route?

how many minimum-price routes are there? (modulo 109+7)
what is the minimum number of flights in a minimum-price route?

what is the maximum number of flights in a minimum-price route?



Input

The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

After this, there are m lines describing the flights. Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.

You may assume that there is a route from Syrjälä to Lehmälä.



Output

Print four integers according to the problem statement.



Constraints

1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
1≤c≤109
Time limit: 1.00 s

Memory limit: 512 MB



Example

Input:

4 5

1 4 5

1 2 4

2 4 5

1 3 2

3 4 3

Output:

5 2 1 2

 2
  \
  (4)
    \
     1--(5)--4
    /        |
  (2)        |
  /          |
 3 ----(3)---+


 */