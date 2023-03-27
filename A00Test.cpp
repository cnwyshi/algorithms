#include <bits/stdc++.h>
using namespace std;
int main(){
    set<vector<int>> s;
    vector<int> a = {1, 2, 3};
    vector<int> b = {1, 2, 3};
    vector<int> c = {1, 2, 3};
    s.insert(a);
    s.insert(b);
    s.insert(c);
    cout << s.size() << endl;
}
