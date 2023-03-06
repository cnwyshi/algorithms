#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        int k = s.size();
        bool palindrome = true;
        for (int j = 0; j < k; j++) {  // 141, 12321
            if (s[j] != s[(k - 1) - j]) {
                palindrome = false;
                break;
            }
        }
        if (palindrome == true) {
            cout << i << endl;
        }
    }
    return 0;
}