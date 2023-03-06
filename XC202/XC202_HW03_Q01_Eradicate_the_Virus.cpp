#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    int v, k;
    cin >> v >> k;
    vector<int> vir(v);
    for (int i = 0; i < v; i++) {
        cin >> vir[i];
    }
    int maxNum = 0;
    for (int i = 0; i < v; i++) {
        if (i >= v - maxNum){
            break;
        }
        int sum = 0;
        bool found = false;
        for (int j = i; j < v; j++) {
            sum += vir[j];
            if (sum > k) {
                maxNum = max(maxNum, j - i);
                found = true;
                break;
            }
        }
        if (!found) maxNum = max(maxNum, v - i);
    }
    cout << maxNum;
}