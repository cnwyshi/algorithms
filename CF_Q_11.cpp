#include <bits/stdc++.h>
using namespace std;
void sort_books(){
    int n, k;
    cin >> n >> k;
    vector<int> books (n);
    vector<int> ans (k);
    for(int i = 0; i < n; i ++){
        char x;
        cin >> x;
        books[x-'a']++;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j ++){
            books[j]--;
            if(books[j] == 0){
                char current = char(j+97);
                ans.push_back(current);
            }
        }
    }
    for(int i = 0; i < k; i++){
        cout << ans[i];
    }
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i ++){
        sort_books();
    }
}