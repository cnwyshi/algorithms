#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s1[N], s2[N];
int t, n, m, cnt[26];

bool check(int x)
{
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++)
        cnt[s1[i] - 'a']++;
    for (int i = 0; i < n; i++)
        if (cnt[s2[i] - 'a']-- <= 0)
            return false;
    int sum = 0;
    for (int i = 0; i < 26; i++)
        sum += cnt[i] > 0;
    return sum <= x;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%s", s1, s2);
        n = strlen(s1);
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%d\n", l == n ? -1 : l);
    }
    return 0;
}

/*
5
abc
abc
BBC
ABC
abc
bbc
ABCD
BACD
ABC
BCB


 */