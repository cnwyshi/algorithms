#include <bits/stdc++.h>
using namespace std;

int w, h;
int xD[] = {-1, 0, 1, 0};
int yD[] = {0, 1, 0, -1};
int cnt = 0;

void floodfill (int x, int y, vector<vector<char>>& building) {
    cnt++;
    building[x][y] = '.';
    for(int i = 0; i < 4; i++) {
        int xx = x + xD[i];
        int yy = y + yD[i];
        if(xx < 0 || xx >= h || yy < 0 || yy >= w || building[xx][yy] != '.') {
            continue;
        }
        // cout << xx << " " << yy << endl;
        if(building[xx][yy] == '*') {
            floodfill(xx, yy, building);
        }
    }
}

int main() {
    cin >> w >> h;
    vector<vector<char>> building(h, vector<char>(w));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cout << i << " " << j << endl;
            cin >> building[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(building[i][j] == '*') {
                cnt = 0;
                floodfill(i, j,building);
                cout << i << " " << j << " " << cnt << endl;
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}
/*
SAMPLE INPUT

11 5
.**........
****....***
.....*****.
.**....****
.***....**.
SAMPLE OUTPUT

14
 */