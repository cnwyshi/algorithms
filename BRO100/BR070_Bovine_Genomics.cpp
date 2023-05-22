#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    // Each genome and the individual characters in each genome
    vector<vector<char>> spotted_cows(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotted_cows[i][j];
        }
    }

    vector<vector<char>> plain_cows(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain_cows[i][j];
        }
    }

    int poss_positions = 0;
    // Iterate through every character
    for (int i = 0; i < m; i++) {
        bool dupe = false;
        // Iterate through every genome
        for (int j = 0; j < n; j++) {
            // Compare to every other genome
            for (int k = 0; k < n; k++) {
                /*
                 * If there are any duplicates,
                 * then this isn't a possible position,
                 * so we can stop counting and make sure we don't count it
                 */
                if (spotted_cows[j][i] == plain_cows[k][i]) {
                    dupe = true;
                    break;
                }
            }
        }
        /*
         * If we haven't found any equal characters,
         * then there are no duplicates and this is a possible sequence
         */
        if (!dupe) {
            poss_positions++;
        }
    }

    cout << poss_positions << endl;
}