//
// Created by genius on 1/4/2023.
//

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    vector<bool> visited(n+1);
    int j = n-1, ans = 0;
    for(int i = 0; i < 5; i++){
        cin >> start[i];
    }
    for(int i = 0; i < 5; i++){
        cin >> end[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(visited[i] == true){
            j--;
        }
        if(start[i] != end[j]){
            visited[start[i]] = true;
            ans++;
        }
        else if(start[i] == end[j]){
            i--;
            j--;
        }
    }
    cout << ans << endl;
}
/*
 */