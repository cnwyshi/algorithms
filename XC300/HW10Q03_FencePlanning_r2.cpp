#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> cows;
int n, m;
vector<vector<int> > connects;
unordered_set<int> visited;
vector<int> coors;
vector<int> q;
void find_coor(int i){
    coors[0] = cows[i].first < coors[0]? cows[i].first:coors[0];
    coors[1] = cows[i].first > coors[1]? cows[i].first:coors[1];
    coors[2] = cows[i].second < coors[2]? cows[i].second:coors[2];
    coors[3] = cows[i].second > coors[3]? cows[i].second:coors[3];
    for(int c = 0; c < connects[i].size();c++){
        if(visited.find(connects[i][c]) == visited.end()){
            q.push_back(connects[i][c]);
            visited.insert(connects[i][c]);
        }
    }
    if(!q.empty()){
        int lq = q.back();
        q.pop_back();
        find_coor(lq);
    }
}

int main(){

    cin >> n >> m;
    int x, y;
    cows.push_back(make_pair(0, 0));
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        cows.push_back(make_pair(x, y));
    }
    int a, b;
    connects.resize(n + 1);
    // connects[0].push_back(0);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        connects[a].push_back(b);
        connects[b].push_back(a);
    }
    int tmp, result = INT_MAX;
    for(int i = 1; i < n + 1; i++){
        if(visited.find(i) == visited.end()){
            visited.insert(i);
            coors = {INT_MAX, 0, INT_MAX, 0};
            find_coor(i);
            tmp = 2 * (coors[1] - coors[0]) + 2*(coors[3] - coors[2]);
            result = result > tmp? tmp: result;
        }
    }
    cout << result << endl;
    return 0;
}