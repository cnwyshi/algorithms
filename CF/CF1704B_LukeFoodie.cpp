#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

// https://codeforces.com/problemset/problem/1704/B
// 贪心
#include <cstdio>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n, x; scanf("%ld %ld", &n, &x);
        long cnt(0), low(0), high(2e9 + 7);
        for(long p = 0; p < n; p++){
            long cur; scanf("%ld", &cur);
            long left = cur - x;
            long right = cur + x;
            low  = (low > left) ? low : left;
            high = (high < right) ? high : right;
            if(low > high){++cnt; low = left; high = right;}
        }
        printf("%ld\n", cnt);
    }

}

/*
1
5 3
1 6 2 2 2

7
5 3
3 8 5 6 7
5 3
3 10 9 8 7
12 8
25 3 3 17 8 6 1 16 15 25 17 23
10 2
1 2 3 4 5 6 7 8 9 10
8 2
2 4 6 8 6 4 12 14
8 2
2 7 8 9 6 13 21 28
15 5
11 4 13 23 7 10 5 21 20 11 17 5 29 16 11

*/