//
// Created by genius on 10/1/22.
//

#include <iostream>
#include <array>

using namespace std;
int order = 0;
bool vis[11];
void permutations(int n, int k, int m, array<int, 11>& a) {

    if(m == n){
        order++;
        if (order == k) {
            for( int i = 0; i<n; i++){
                cout << a[i] << " ";
            }
            return;
        }
    }
    else{
        for(int i = 1; i<=n; i++){
            if(vis[i] != 0) continue;
            vis[i] = 1;
            a[m] = i;
            permutations(n, k,m+1, a);
            vis[i] = 0;
        }
    }
}


int main() {
    int n;
    int k;
    array<int, 11> a;
    cin >> n >> k;
    permutations(n, k, 0, a);
}