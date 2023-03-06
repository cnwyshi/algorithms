#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
int main(){
    int n, count;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        int g = 0, h = 0;
        for(int j = i; j < n; j++){
            if(s[j] == 'G'){
                g++;
            }
            else{
                h++;
            }
            if(g+h>=3 && (h==1 || g == 1)){
                count++;
            }
        }
    }
    cout << count << endl;
}