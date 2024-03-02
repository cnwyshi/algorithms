#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define MAXN 100100

int n;
int ans[MAXN];

int main() {

    scanf("%d", &n);

    int cv = n - 1;
    int ind = 1;
    while (abs(cv) > 1) {
        ans[ind] = cv;
        ind += cv;
        cv *= -1;
        if (cv > 0) cv--;
        else cv++;
    }

    if (n % 2) {
        ans[ind] = 1;
        ans[ind - 1] = n;
    }

    else {
        ans[ind] = -1;
        ans[ind + 1] = n;
    }

    printf("%d\n%d\n", n - 1, 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");

}