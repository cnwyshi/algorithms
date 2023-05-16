#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int sum = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        sum = sum + (s[i] - '0');  // '1'
    }
    cout << sum << endl;
    return 0;

}