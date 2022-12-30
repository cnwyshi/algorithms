#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int n,a[100010];

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        a[i] = min(a[i] - 1,1000000 - a[i]);
    }
    sort(a + 1,a + 1 + n);
    printf("%d\n",a[n]);

    return 0;
}