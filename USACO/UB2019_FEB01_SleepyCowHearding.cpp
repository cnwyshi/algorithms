#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> cow(3);
    ifstream fin ("herding.in");
    fin >> cow[0] >> cow[1] >> cow[2];
    sort(cow.begin(), cow.end());

    ofstream fout ("herding.out");
    if (cow[0]+2==cow[2]) {
        fout << "0\n";
    }  else if (cow[0]+2==cow[1] || cow[1]+2==cow[2]) {
        fout << "1\n";
    } else {
        fout << "2\n";
    }
    fout << max(cow[1] - cow[0], cow[2] - cow[1]) - 1 << "\n";
    return 0;
}

// http://www.usaco.org/index.php?page=viewproblem2&cpid=915
