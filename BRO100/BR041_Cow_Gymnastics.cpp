#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int index(const vector<T>& vec, const T& n) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == n) {
            return i;
        }
    }
    return -1;
}

int main() {
    int session_num;
    int cow_num;
    cin >> session_num >> cow_num;
    vector<vector<int>> sessions(session_num, vector<int>(cow_num));
    for (int s = 0; s < session_num; s++) {
        for (int c = 0; c < cow_num; c++) {
            cin >> sessions[s][c];
            sessions[s][c]--;
        }
    }

    int better_pairs = 0;
    for (int c1 = 0; c1 < cow_num; c1++) {
        for (int c2 = 0; c2 < cow_num; c2++) {
            if (c1 == c2) {
                continue;
            }

            bool better = true;
            for (const vector<int>& s : sessions) {
                if (index(s, c1) < index(s, c2)) {
                    better = false;
                    break;
                }
            }
            better_pairs += better;
        }
    }

    cout << better_pairs << endl;
}