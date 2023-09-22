#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct BST{
    struct node{
        int value;
        node* left;
        node* right;
    };

    node* root = NULL;

    node* insert(int value, node* cur){
        if (cur == NULL){
            cur = new node{value, NULL, NULL};
            return cur;
        }else if (value < cur->value){
            cur->left = insert(value, cur->left);
        }else{
            cur->right = insert(value, cur->right);
        }
        return cur;
    }

    // Go as far left as possible
    node* findMin(node* cur){
        if (cur->left == NULL){
            return cur;
        }
        return findMin(cur->left);
    }

    node* findMax(node* cur){
        if (cur->right == NULL){
            return cur;
        }
        return findMax(cur->right);
    }

    node* find(int value, node* cur){
        if (value == cur->value){
            return cur;
        } else if (value < cur->value){
            return find(value, cur->left);
        }else{
            return find(value, cur->right);
        }
    }

    void _precedence(int value, int& cur_best, node*& cur){
        if (cur->value >= value){
            if (cur->left)
                _precedence(value, cur_best, cur->left);
        }else{
            cur_best = max(cur_best, cur->value);
            if (cur->right)
                _precedence(value, cur_best, cur->right);
        }
    }

    void _successor(int value, int& cur_best, node*& cur){
        //cout << "AT " << value << "\n";
        if (cur->value > value){
            cur_best = min(cur_best, cur->value);
            //cout << "TRYING TO FIND " << value << " WITH CUR_BEST " << cur_best << " GOING LEFT\n";
            if (cur->left)
                _successor(value, cur_best, cur->left);
        }else{
            if (cur->right)
                _successor(value, cur_best, cur->right);
        }
    }

    int precedence(int operand){
        int res = INT32_MIN;
        _precedence(operand, res, root);
        return res;
    }

    int successor(int operand){
        int res = INT32_MAX;
        _successor(operand, res, root);
        return res;
    }

    node* remove(int target, node* cur){
        node* garbage; // for garbage collection
        if (cur == NULL){
            return NULL;
        }else if (target < cur->value){
            cur->left = remove(target, cur->left);
        }else if (target > cur->value){
            cur->right = remove(target, cur->right);
        }else if (cur->left && cur->right){ // I am the target and I have 2 children
            node* replacement = findMax(cur->left);
            cur->value = replacement->value;
            cur->left = remove(replacement->value, cur->left);
        }else{ // I am the target and I only have <= 1 child
            garbage = cur;
            if (cur->left == NULL){
                cur = cur->right;
            }else if (cur->right == NULL){
                cur = cur->left;
            }
            delete garbage;
        }
        return cur;
    }

    int size(node* cur){
        if (cur == NULL){
            return 0;
        }
        return size(cur->left) + size(cur->right) + 1;
    }

    int find_rank(int target, node*& cur){
        int rank = 0;

        while (true){
            if (cur->value < target){ // Go to right side
                if (cur->left){
                    rank += size(cur->left);
                }
                rank += 1;
                cur = cur->right;
            }else if (cur->value > target){
                cur = cur->left;
            }else{
                if (cur->left){
                    rank += size(cur->left);
                }
                return rank + 1;
            }
        }
    }

    int find_element_with_rank(int rank, node*& cur){
        int cur_rank = 0;
        //cout << cur->value << " " << cur->size << "\n";
        while (true){
            int left_size = 0;
            //cout << "CALCULATING LEFT\n";
            if (cur->left){
                //cout << "ACCESSING" << "\n";
                left_size = size(cur->left);
            }
            //cout << "DONE << " << left_size << " \n";

            if (left_size + cur_rank + 1 == rank){
                //cout << "OUTPUTTING\n";
                return cur->value;
            }

            if (rank <= left_size){
                //cout << "GOING LEFT\n";
                cur = cur->left;
            }else if (rank > left_size + 1){
                //cout << "GOING RIGHT\n";
                cur_rank += left_size + 1;
                cur = cur->right;
            }
        }
    }

    void print() { inorder(root); cout << '\n'; }
    void inorder(node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }
};

int main(){
    //freopen("sample.out", "w", stdout);
    //freopen("sample (3).in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    BST tree;

    int num_ops;
    cin >> num_ops;

    for (int i = 0; i < num_ops; i++){
        int id, operand;
        cin >> id >> operand;
        cout << id << ' ' << operand << endl;
        if (id == 1){
            tree.root = tree.insert(operand, tree.root);
            // tree.print();
        }else if (id == 2){
            tree.root = tree.remove(operand, tree.root);
            // tree.print();
        }else if (id == 3) {
            cout << tree.find_rank(operand, tree.root) << "\n";
        }else if (id == 4) {
            cout << tree.find_element_with_rank(operand, tree.root) << "\n";
        }else if (id == 5) {
            cout << tree.precedence(operand) << "\n";
        }else if (id == 6) {
            cout << tree.successor(operand) << "\n";
        }else{
            cout << tree.root->value << "\n";
        }
    }
}