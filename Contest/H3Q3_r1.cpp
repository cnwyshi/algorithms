#include <bits/stdc++.h>

using namespace std;
static const auto fast = []() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class BST {
    class Node {
        friend class BST;

        int val = -1, n = 1, c = 1;
        Node *left = nullptr, *right = nullptr;

        Node(int v) : val(v) {}
    };

    Node *root = nullptr;

    Node *insert(Node *node, int v) {
        if (node == nullptr) {
            node = new Node(v);
        } else if (v < node->val) {
            node->left = insert(node->left, v);
        } else if (node->val < v) {
            node->right = insert(node->right, v);
        } else {
            node->c++;
        }
        node->n = count(node->left) + count(node->right) + node->c;
        return node;
    }

    Node *find(Node *node, int v) {
        if (v < node->val) {
            return find(node->left, v);
        } else if (node->val < v) {
            return find(node->right, v);
        }
        return node;
    }

    Node *predecessor(Node *node, int v) {
        if (node == nullptr) {
            return nullptr;
        }
        Node *ans = nullptr;
        while (node != nullptr) {
            if (node->val < v) {
                ans = node;
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return ans;
    }

    // https://leetcode.cn/submissions/detail/164727701/
    Node *successor(Node *node, int v) {
        if (node == nullptr) {
            return nullptr;
        }
        Node *ans = nullptr;
        while (node != nullptr) {
            if (v < node->val) {
                ans = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return ans;
    }

    Node *min(Node *node) {
        return node->left == nullptr ? node : min(node->left);
    }

    Node *max(Node *node) {
        return node->right == nullptr ? node : max(node->right);
    }

    int count(Node *node) {
        return node == nullptr ? 0 : node->n;
    }

    Node *del(Node *node, int v) {
        if (node == nullptr) {
            return nullptr;
        }
        if (v < node->val) {
            node->left = del(node->left, v);
        } else if (node->val < v) {
            node->right = del(node->right, v);
        } else if (node->c > 1) {
            node->c--;
        } else {
            if (node->left == nullptr) {
                return node->right;
            } else if (node->right == nullptr) {
                return node->left;
            }
            Node *t = node;
            node = min(node->right);
            node->right = del(t->right, node->val);
            node->left = t->left;
            delete t;
        }
        node->n = count(node->left) + count(node->right) + node->c;
        return node;
    }

    Node *findKth(Node *node, int k) {
        if (node == nullptr) {
            return nullptr;
        }
        int m = count(node->left);
        if (k <= m) {
            return findKth(node->left, k);
        } else if (m + node->c < k) {
            return findKth(node->right, k - m - node->c);
        }
        return node;
    }

    int rank(Node *node, int v) {
        if (node == nullptr) {
            return 0;
        } else if (v < node->val) {
            return rank(node->left, v);
        } else if (node->val < v) {
            return count(node->left) + node->c + rank(node->right, v);
        }
        return count(node->left) + 1;
    }


public:
    void insert(int v) { root = insert(root, v); }

    void del(int v) { del(root, v); }

    int count() { return count(root); }

    int findKth(int k) { return findKth(root, k)->val; }

    int rank(int v) { return rank(root, v); }

    int predecessor(int v) {
        Node *p = predecessor(root, v);
        return p == nullptr ? INT_MIN : p->val;
    }

    int successor(int v) {
        Node *s = successor(root, v);
        return s == nullptr ? INT_MAX : s->val;
    }

    void print() {
        inorder(root);
        cout << '\n';
    }

    void inorder(Node *node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->val << '(' << node->c << ") ";
            inorder(node->right);
        }
    }
};

int main() {
    int n, op, v;
    cin >> n;
    BST bst;
    for (int i = 0; i < n; i++) {
        cin >> op >> v;
        cout << op << ' ' << v << endl;
        if (op == 2 && v == 71) {
            cout << 'a' << endl;
        }
        if (op == 1) {
            bst.insert(v);
//            bst.print();
        } else if (op == 2) {
            bst.del(v);
//            bst.print();
        } else if (op == 3) {
            cout << bst.rank(v) << '\n';
        } else if (op == 4) {
            cout << bst.findKth(v) << '\n';
        } else if (op == 5) {
            cout << bst.predecessor(v) << '\n';
        } else if (op == 6) {
            cout << bst.successor(v) << '\n';
        }
    }
}

/*
You have to write a data structure to maintain some data. The following operations should be provided:
1. Insert number x
2. Delete x（If there are several identical numbers, only delete one of them）
3. Find the rank of x（if there are several identical numbers, print the rank with the smallest value）
4. Find the number whose rank is x
5. Find the predecessor of x （defined as the largest number that is less than x）
6. Find the successor of x（defined as the smallest number which is greater than x）

Sample input 1：
10
1 92
1 91
3 91
4 1
1 50
4 2
1 100
1 64
1 64
6 59

Sample output 1：
1
91
91
64

*/
