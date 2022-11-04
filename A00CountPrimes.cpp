#include <vector>

using namespace std;

class Solution {
public:
    // Time: O(N * sqrt(N))
    /* Steps:       n = 100, ans = 25
    */
    int countPrimes(int n) {
        vector<bool> composite(n + 1);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (composite[i]) {
                continue;
            }
            for (int j = i * 2; j < n; j += i) {
                composite[j] = true;
            }
        }
        for (int i = 2; i < n; i++) {
            if (composite[i] == false) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}

/*
100 
2, 3 , 4 ..... 100
2  no more 4 6 8 10 12 14... 100
3 no more 6 9 ... 99
*/
