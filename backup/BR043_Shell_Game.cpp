#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    // shell_at_position[i] stores the label of the shell located at position i
    vector<int> shell_at_position(3);
    // Place the shells down arbitrarily
    for (int i = 0; i < 3; i++) {
        shell_at_position[i] = i;
    }

    // counter[i] stores the number of times the shell with label i was picked
    vector<int> counter(3);
    for (int i = 0; i < n; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        // Zero indexing: offset all positions by 1
        a--, b--, g--;

        // Perform Bessie's swapping operation
        std::swap(shell_at_position[a], shell_at_position[b]);
        // Count the number of times Elsie guesses each particular shell
        counter[shell_at_position[g]]++;
    }

    cout << std::max({counter[0], counter[1], counter[2]}) << endl;
}