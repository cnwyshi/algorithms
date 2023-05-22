// Source: https://usaco.guide/general/io

#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> nums;
    while (n--) {
        int x;
        cin >> x;
        nums[x]++;
    }
    for (auto i = nums.begin(); i != nums.end(); i++) {
        cout << i->first << " " << i->second << endl;
    }
}
