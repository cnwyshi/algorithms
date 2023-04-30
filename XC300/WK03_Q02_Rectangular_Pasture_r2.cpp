#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

bool ycomp(Point p, Point q) { return p.second < q.second; }

const int MAX_N = 2500;
int N, Psum[MAX_N + 1][MAX_N + 1];
Point P[MAX_N];

int rsum(int x1, int y1, int x2, int y2) {
    return Psum[x2 + 1][y2 + 1] - Psum[x2 + 1][y1] - Psum[x1][y2 + 1] + Psum[x1][y1];
}

int main(void) {
    cin >> N;
    map<int, int> xindex, yindex;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P[i] = make_pair(x, y);
        xindex[x] = 0;
        yindex[y] = 0;
    }
//    sort(P, P + N);
//    for (int i = 0; i < N; i++) P[i].first = i + 1;
//    sort(P, P + N, ycomp);
//    for (int i = 0; i < N; i++) P[i].second = i + 1;
    int index = 0;
    for (auto it = xindex.begin(); it != xindex.end(); it++) {
        it->second = index++;
    }
//    for (auto it = xindex.begin(); it != xindex.end(); it++) {
//        cout << it->first << " " << it->second << endl;
//    }

    index = 0;
    for (auto i = yindex.begin(); i != yindex.end(); i++) {
        i->second = index++;
    }
//    for (auto it = yindex.begin(); it != yindex.end(); it++) {
//        cout << it->first << " " << it->second << endl;
//    }
    ofstream ofs1("position-r1.txt");
    for (int i = 0; i < N; i++) {
        P[i].first = xindex[P[i].first];
        P[i].second = yindex[P[i].second];
//        cout << P[i].first << " " << P[i].second << endl;
        ofs1 << P[i].first << " " << P[i].second << endl;
    }

    for (int i = 0; i < N; i++) {
        Psum[P[i].first + 1][P[i].second + 1] = 1;
    }

    ofstream ofs2("prefix-r1.txt");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Psum[i][j] += Psum[i - 1][j] + Psum[i][j - 1] - Psum[i - 1][j - 1];
            ofs2 << Psum[i][j] << " ";
        }
        ofs2 << endl;
    }
    ofstream ofs("pasture-r1.txt");
    long long answer = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++) {
            int x1 = min(P[i].first, P[j].first);
            int x2 = max(P[i].first, P[j].first);
            int left = min(P[i].first, P[j].first);
            int right = max(P[i].first, P[j].first);
            int top = min(P[i].second, P[j].second);
            int bottom = max(P[i].second, P[j].second);
            answer += rsum(0, top, left, bottom) * rsum(right, top, N - 1, bottom);
            ofs << i << " " << j << " " << rsum(0, top, left, bottom) << " " << rsum(right, top, N - 1, bottom) << endl;
//            printf("%d\t%d\t%d\n", i, j, rsum(0, i, x1, j) * rsum(x2, i, N - 1, j));
        }
    cout << answer + 1 << "\n";

}