#include <climits>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int totalLevel, startLevel, endLevel;
vector<int> nextLevels;
vector<bool> visited;
int minSteps = INT_MAX;

void dfs(int currentLevel, int steps) {
    if (currentLevel == endLevel) {
        minSteps = min(minSteps, steps);
    }
    for (int i = -1; i <= 1; i += 2) {
        int nextLevel = currentLevel + i * nextLevels[currentLevel - 1];
        if (nextLevel > 0 && nextLevel <= totalLevel && !visited[nextLevel]) {
            visited[nextLevel] = true;
            dfs(nextLevel, steps + 1);
        }
    }
}

int main() {
    cin >> totalLevel;
    cin >> startLevel;
    cin >> endLevel;

    if (startLevel == endLevel) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < totalLevel; i++) {
        int nextLevel;
        cin >> nextLevel;
        nextLevels.push_back(nextLevel);
        visited.push_back(false);
    }

    if (endLevel <= 0 || endLevel > totalLevel) {
        cout << -1 << endl;
    } else {
        dfs(startLevel, 0);
        cout << (minSteps == INT_MAX ? -1 : minSteps) << endl;
    }

    return 0;
}