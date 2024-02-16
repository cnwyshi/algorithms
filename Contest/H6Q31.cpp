#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
map<ll, vector<pll>> adj;

int solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> dist(n + 1, inf);
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> queue;
    map<ll, ll> routes;
    map<ll, ll> min_flights;
    map<ll, ll> max_flights;

    routes[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;
    queue.push({0, 1});
    while (!queue.empty()) {
        auto [distance, node] = queue.top();
        queue.pop();
        if (dist[node] < distance) {
            continue;
        }
        for (auto [neighbor, weight]: adj[node]) {
            if (distance + weight < dist[neighbor]) {
                dist[neighbor] = distance + weight;
                queue.push({dist[neighbor], neighbor});
                routes[neighbor] = routes[node];
                min_flights[neighbor] = min_flights[node] + 1;
                max_flights[neighbor] = max_flights[node] + 1;
            } else if (distance + weight == dist[neighbor]) {
                routes[neighbor] = (routes[neighbor] + routes[node]) % MOD;
                if (min_flights.count(neighbor) == 0) {
                    min_flights[neighbor] = inf;
                }
                min_flights[neighbor] = min(min_flights[neighbor], min_flights[node] + 1);
                max_flights[neighbor] = max(max_flights[neighbor], max_flights[node] + 1);
            }
        }
    }
    cout << dist[n] << " " << routes[n] << " " << min_flights[n] << " " << max_flights[n];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
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
 */