#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> group(n);
    int group_no = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == "or"){
            group_no++;
        }
        else{
            if(i % 2 == 0){
                group[i] = group_no;
            }
        }
    }
    vector<int> first_false(group_no + 1, INF);
    vector<int> last_false(group_no + 1, -1);
    for(int i = 0; i < n; i += 2){
        int g = group[i];
        if(s[i] == "false"){
            if(first_false[g] == INF){
                first_false[g] = i;
            }
            last_false[g] = i;
        }
    }
    int total_first_true = INF, total_last_true = -1;
    for(int i = 0; i <= group_no; i++){
        if(first_false[i] == INF){
            if(total_first_true == INF){
                total_first_true = i;
            }
            total_last_true = i;
        }
    }
    while(q--){
        int l, r; cin >> l >> r;
        --l; --r;
        string t; cin >> t;
        // we only need one true for whole statement to be true
        int l_group = group[l], r_group = group[r];
        if(total_first_true < l_group || total_last_true > r_group){
            cout << (t == "true" ? 'Y' : 'N');
            continue;
        }
        if(t == "true"){
            cout << (first_false[l_group] < l || last_false[r_group] > r ? 'N' : 'Y');
        }
        else{
            cout << 'Y';
        }
    }
}