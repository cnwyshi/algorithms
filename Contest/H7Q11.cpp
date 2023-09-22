#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = 1e18;
static const auto fast = []() { std::ios_base::sync_with_stdio(0); cin.tie(0); return 0;}();

int solve() {
	int n, m, q, a, b, c;
	cin >> n >> m >> q;
	vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
	for (int i = 1; i <= n; ++i) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = min(dist[a][b], c + 0LL);
	}

	// Floyd-Warshall
	for (ll k = 1; k <= n; ++k) {
		for (ll i = 1; i <= n; ++i) {
			for (ll j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		cin >> a >> b;
		cout << (dist[a][b] == inf ? -1 : dist[a][b]) << '\n';
	}
	return 0;
}

int main() {
	solve();
}

/*
A.  Shortest Routes II
Problem ID: 14122
Contest ID: 5258
必做题
Time limit: 1.00 s
Memory limit: 512 MB
There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

Input

The first input line has three integers n, m and q: the number of cities, roads, and queries.

Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.

Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.

Output

Print the length of the shortest route for each query. If there is no route, print −1 instead.

Constraints
1≤n≤500
1≤m≤n2
1≤q≤105
1≤a,b≤n
1≤c≤109
Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
*/