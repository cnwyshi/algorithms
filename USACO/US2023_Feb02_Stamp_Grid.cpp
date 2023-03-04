#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, t, ans = 0;
    cin >> n >> t;
    vector<int> d(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> d[i] >> b[i];
        d[i] --;
        b[i]--;
    }
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(cnt == t){
            break;
        }
        if(cnt >= d[i]){
            for(int j = cnt; j <= min(cnt + b[i], t); j++){
                ans++;
            }
            cnt = cnt + b[i];
        }
        else{
            cnt = d[i];
            for(int j = cnt; j < min(cnt + b[i], t); j++){
                ans++;
            }
            cnt = cnt + b[i];
        }
    }
    cout << ans << endl;
}
/*
4

2
**
*.
1
*

3
.//
./*
%**
2
.*
**

3
...
.*.
...
3
.*.
...
...

3
**.
.**
..*
2
.*
*.


1 2
3 4

3 1
4 2

1 2 3
4 5 6
7 8 9

1 4 7
2 5 8
3 6 9

 9 8 7
 6 5 4
 3 2 1

 3 6 9
 2 5 8
 1 5 7

 7 4 1
 8 5 2
 9 6 3


*/