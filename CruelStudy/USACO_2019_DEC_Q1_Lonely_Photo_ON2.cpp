//
// Created by genius on 1/2/2023.
//
//
// Created by genius on 1/2/2023.
//

//V1
#include <bits/stdc++.h>
using namespace std;
int main_V1(){
    int n, count;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n-2; i++){
        int g = 0, h = 0;
        for(int j = i; j < n; j++){
            if(s[j] == 'G'){
                g++;
            }
            else{
                h++;
            }
            if((j-i+1>3) && (h==1 || g == 1)){
                count++;
            }
        }
    }
    cout << count << endl;
}
//V2
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        int l = 0, r = 0, li = i-1, ri = i+1;
//        cout << s[li] << s[i] << endl;
        while(li >= 0 && s[li] != s[i]){
//            cout << s[li] << s[i];
            l++;
            li--;
        }
//        cout << s[ri] << s[i] << endl;
        while(ri < n && s[ri] != s[i]){
            r++;
            ri--;
        }
//        cout << l << r << endl;
        count += l*r + max(0, l-1) + max(0, r-1);
    }
    cout << count;
}
