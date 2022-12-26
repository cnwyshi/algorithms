<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
void dfs(int n, int p, int i, int s, vector<char>& ops) {
    if (i == n) {
        if (s == 0) {
            for (int j = 0; j < n; j ++) {
                cout << ops[j] << (j + 1);
            }
            cout << endl;
        }
        return;
    }
    ops[i] =  ' ';
    int v = p >= 0 ? p * 10 + i + 1 : p * 10 - i - 1;
    dfs(n, v, i + 1, s - p + v, ops);   // 12
    if (i > 0) {
        ops[i] = '+';
        dfs(n, i + 1, i + 1, s + i + 1, ops);
        ops[i] = '-';
        dfs(n, -i - 1, i + 1, s - i - 1, ops);
    }
}
int main() {
    int n;
    cin >> n;
    vector<char> ops(n);
    dfs(n, 0, 0, 0, ops);
    return 0;
}

/*
n = 7
1+2+3

i = 0, s = 0 -> s = 1

i = 1, p = 1
  i = 2
      1 + 2
      1 - 2
      12

      1-3
dfs(1)
 1
 - s*10-i
 +
curvall*10
 curvall - i
 curvall *10 +i
 vtotal += urvall *10 +1

 i = 1,  1 - 2,
    i = 2, p = -2, s = -1, "", s' = -1 - -2 + -2 * 10 - 3 = 1 - 23 = -22
*/
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int> list;
void dfs(int index, string output, int current, int sum, int sign) {
    if(index == n-1){
        output += to_string(list[n-1]);
        sum = sum + (current*10 + list[n-1])*sign;
        if(sum==0) {
            cout<< output << endl;
        }
        return;
    }
    output += to_string(list[index]);
    int new_current = current*10 + list[index];
    dfs(index+1, output + " ", new_current, sum, sign);
    int new_sum = sum + sign*new_current;
    dfs(index+1, output + "+", 0, new_sum, 1);
    dfs(index+1, output + "-", 0, new_sum, -1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        list.push_back(i+1);
    }
    dfs(0,"",0,0,1);
}
>>>>>>> Final Exam
