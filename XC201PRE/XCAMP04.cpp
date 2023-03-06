#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        bool prime = true;
        if (n == 1) {
            cout << "No" << endl;
            continue;
        }
        for (int j = 2; j <= n / 2; j++) {
            if (n % j == 0 && n != 2) {
                prime = false;
                break;
            }

        }
        if (n == 2) {
            cout << "Yes" << endl;
            continue;
        }
        if (prime == false) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}