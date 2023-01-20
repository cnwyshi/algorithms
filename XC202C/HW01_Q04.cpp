//
// Created by genius on 1/8/23.
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int  n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
}