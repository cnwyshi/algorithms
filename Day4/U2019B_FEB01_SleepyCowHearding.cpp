#include <bits/stdc++.h>

using namespace std;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=915
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    int a, b, c;
    ifstream fin ("herding.in");
    fin >> a >> b >> c;

    // Arrange in sorted order
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);

    ofstream fout ("herding.out");
    if (c==a+2)
        fout << "0\n";
    else if (b==a+2 || c==b+2)
        fout << "1\n";
    else fout << "2\n";
    fout << max(b-a, c-b) - 1 << "\n";
    return 0;
}