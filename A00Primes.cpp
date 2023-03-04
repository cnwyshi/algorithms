#include <iostream>
#include <vector>

using namespace std;

// Question: list all prime numbers under N
// https://oi-wiki.org/math/number-theory/prime/
// https://oi-wiki.org/math/number-theory/sieve/
// 关于素数那点事儿, https://www.youtube.com/watch?v=2STiK6U41qQ&list=PLYtoePJQbGmi1WWaa3p73X7TalChgRyIf
// 如何快速筛选质数？费马素性检验和米勒-拉宾测试, https://www.youtube.com/watch?v=E5vtn_OIe-c

// Solution 0: Brute Force
// Time: O(N^2)
// Space: O(1)
vector<int> PrimeBruteForce(int n) {
    vector<int> ans;
    for (int v = 2; v <= n; v++) {
        bool prime = true;
        for (int f = 2; f < v; f++) {
            if (v % f == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            ans.push_back(v);
        }
    }
    return ans;
}

// Solution 1: Smart
// Time: O(N*Sqrt(N))
// Space: O(1)
vector<int> PrimeSmart(int n) {
    vector<int> ans;
    for (int v = 2; v <= n; v++) {
        bool prime = true;
        for (int f = 2; f * f <= v; f++) {
            if (v % f == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            ans.push_back(v);
        }
    }
    return ans;
}

// Solution 2: Eratosthenes
// Time: O(N*LogLogN)
// Space: O(N)
vector<int> SieveOfEratos(int n) {
    vector<int> prime(n + 1, 1), ans;
    for (int f = 2; f <= n; f++) {
        if (prime[f]) {
            for (int v = f * f; v <= n; v += f) {
                prime[v] = 0;
            }
        }
    }
    for (int v = 2; v <= n; v++) {
        if (prime[v]) {
            ans.push_back(v);
        }
    }
    return ans;
}

// Solution 2: Euler
// Time: O(N)
// Space: O(N)
vector<int> sieveEuler(int n) {
    vector<int> prime(n + 1, 1), ans;
    for (int v = 2; v <= n; v++) {
        if (prime[v]) {
            ans.push_back(v);
        }
        for (int i = 0; i < ans.size() && v * ans[i] <= n; i ++) {
            prime[v * ans[i]] = 0;
            if (v % ans[i] == 0) {
                break;
            }
        }
    }
    return ans;
}

int main() {
    cout << sieveBruteForce(100).size() << endl;
    cout << sieveSmart(100).size() << endl;
    cout << sieveEratos(100).size() << endl;
    cout << sieveEuler(100).size() << endl;
}