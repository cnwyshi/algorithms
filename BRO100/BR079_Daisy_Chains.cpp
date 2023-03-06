#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int petals[n];
    for (int i = 0; i < n; ++i) {
        cin >> petals[i];
    }
    int photos = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int totalPetals = 0;
            for (int k = i; k <= j; ++k) {
                totalPetals += petals[k];
            }
            bool present = false;
            for (int k = i; k <= j; ++k) {
                if (petals[k] * (j-i+1) == totalPetals) {
                    present = true;
                }
            }
            if (present) {
                ++photos;
            }
        }
    }
    cout << photos;
    return 0;
}