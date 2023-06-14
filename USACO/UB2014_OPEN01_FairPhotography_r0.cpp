#include <bits/stdc++.h>
using namespace std;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=431
int main() {
    freopen("fairphoto.in", "r", stdin);
    freopen("fairphoto.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> cow(n, vector<int>(2));
    for (int i = 0; i < n; i ++) {
        char c;
        cin >> cow[i][0] >> c;
        cow[i][1] = c == 'G' ? 1 : -1;
    }
    sort(cow.begin(), cow.end());
    map<int, int> last;
    last[0] = cow[0][0];
    for (int i = 0, prefix = 0; i < n; i ++) {
        prefix += cow[i][1];
        if (last.count(prefix)) {
            ans = max(ans, cow[i][0] - cow[last[prefix] + 1][0]);
        } else {
            last[prefix] = i;
        }

    }
    cout << ans << endl;
    return 0;
}

/*
Problem 2: Fair Photography [Brian Dean, 2014]

Farmer John's N cows (1 <= N <= 100,000) are standing at various positions along
a long one-dimensional fence.  The ith cow is standing at position x_i (an
integer in the range 0...1,000,000,000) and has breed b_i (either 'G' for
Guernsey or 'H' for Holstein).  No two cows occupy the same position.

FJ wants to take a photo of a contiguous interval of cows for the county
fair, but we wants all of his breeds to be fairly represented in the photo.
Therefore, he wants to ensure that, for whatever breeds are present in the
photo, there is an equal number of each breed (for example, a photo with
all Holsteins is ok, a photo with 27 Holsteins and 27 Guernseys is ok, but a
photo with 10 Holsteins and 9 Guernseys is not ok).  Help FJ take his fair
photo by finding the maximum size of a photo that satisfies FJ's
constraints.  The size of a photo is the difference between the maximum and
minimum positions of the cows in the photo.  It is possible that FJ could
end up taking a photo of just a single cow, in which case this photo would
have size zero.

PROBLEM NAME: fairphoto

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Line i+1 contains x_i and b_i.

SAMPLE INPUT (file fairphoto.in):

6
4 G
10 H
7 G
16 G
1 G
3 H

INPUT DETAILS:

There are six cows with breeds (from left to right) G, H, G, G, H, G.

OUTPUT FORMAT:

* Line 1: A single integer indicating the maximum size of a fair
        photo.

SAMPLE OUTPUT (file fairphoto.out):

7

OUTPUT DETAILS:

The largest fair photo Farmer John can take is of the middle 4 cows,
containing 2 Holsteins and 2 Guernseys.
*/