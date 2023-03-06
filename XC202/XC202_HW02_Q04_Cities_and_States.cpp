#include <iostream>
#include <map>
#include <cmath>
#include <set>
using namespace std;
int main(){
//    freopen("sample.in", "r", stdin);
    int n;
    cin >> n;
    map <string, int> m;
    long long pairs = 0;
    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        string c = city.substr(0, 2);
        if(c != state){
            pairs += m[state + city.substr(0, 2)];
            m[city.substr(0,2) + state]++;
        }
    }
//    for(auto i: m){
//        cout << i.first << " " << i.second << endl;
//    }
    cout << pairs << "\n";
}
/*
43767
43841
43762
*/