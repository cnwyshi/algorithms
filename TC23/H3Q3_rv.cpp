#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value = -1;
    Node* left;
    Node* right;
};
struct BST {
    Node root;
    BST(int N){root.value = N;}
    void insert(int n){
        Node current = root;
        while (current.value != -1){
            if (n > current.value){
                current = *current.right;
            }
            else current = *current.left;
        }
        current.value = n;
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> bst;
    for (int i = 0; i < n; i++){
        int o, v;
        cin >> o >> v;
        cout << o << ' ' << v << endl;
        if (o == 1){
            bst.push_back(v);
            sort(bst.begin(), bst.end());
        }
        if (o == 2){
            vector<int> newBST;
            bool alrDeleted = false;
            for (int j = 0; j < bst.size(); j++){
                if (bst[j] != v || alrDeleted) newBST.push_back(bst[j]);
                else alrDeleted = true;
            }
            bst = newBST;
            sort(bst.begin(), bst.end());
        }
        if (o == 3){
            for (int i = 0; i < bst.size(); i++){
                if (bst[i] == v) {
                    cout << i+1 << '\n';
                    break;
                }
            }
        }
        if (o == 4){
            cout << bst[v-1] << '\n';
        }
        if (o == 5){
            bool good = false;
            for (int j = 0; j < bst.size(); j++){
                if (bst[j] >= v) {
                    cout << bst[j-1] << '\n';
                    good = true;
                    break;
                }
            }
            if (!good) cout << bst[bst.size() - 1] << '\n';
        }
        if (o == 6){
            cout << *(upper_bound(bst.begin(), bst.end(), v)) << '\n';
        }
    }
}