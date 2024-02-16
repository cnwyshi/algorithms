#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring11(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0, j = 0, d = 0; j < n; j++) {
            if (j != 0 && s[j - 1] == s[j]) {
                d++;
            }
            for (; d > 1; i++) {
                d -= s[i] == s[i + 1];
            }
            ans = max(j - i + 1, ans);
        }
        return ans;
    }

    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0, j = 0, d = 0; j <= n;) {
            if (d > 1) {
                d -= s[i] == s[i + 1];
                i++;
            } else {
                ans = max(j - i, ans);
                if (j > 0 && j < n && s[j - 1] == s[j]) {
                    d++;
                }
                j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestSemiRepetitiveSubstring("52233") << endl;
}