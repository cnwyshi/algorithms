// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cows;
    cows["Bessie"] = 0;
    cows["Elsie"] = 0;
    cows["Daisy"] = 0;
    cows["Gertie"] = 0;
    cows["Annabelle"] = 0;
    cows["Maggie"] = 0;
    cows["Henrietta"] = 0;
    for(int i = 0; i < n; i++){
        string cow;
        int milk;
        cin >> cow >> milk;
        cows[cow] += milk;
    }
    vector<int> m;
    for(auto i = cows.begin(); i != cows.end(); i++){
        m.push_back(i -> second);
    }
    sort(m.begin(), m.end());
    int j = 1;
    while(m[j] == m[j-1] && j < 7){
        j++;
    }
    if(j == 7 || (j < 6 && m[j] == m[j+1])){
        cout << "Tie" << endl;
    }
    else{
        for(auto i = cows.begin(); i != cows.end(); i++){
            if(i -> second == m[j]){
                cout << i -> first << endl;
                return 0;
            }
        }
    }
}
