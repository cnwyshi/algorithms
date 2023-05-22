//
// Created by genius on 1/16/22.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, max = 0;
    cin >> n >> m;

    vector<int> limitSegmentMiles, segmentLimits;
    for (int i = 0; i < n; i++) {
        int segmentMile, segmentLimit;
        cin >> segmentMile >> segmentLimit;
        limitSegmentMiles.push_back(segmentMile);
        segmentLimits.push_back(segmentLimit);
    }
    vector<int> speedSegmentMiles, segmentSpeeds;
    for (int i = 0; i < m; i++) {
        int segmentMile2, segmentSpeed;
        cin >> segmentMile2 >> segmentSpeed;
        speedSegmentMiles.push_back(segmentMile2);
        segmentSpeeds.push_back(segmentSpeed);
    }
    vector<int> mileLimits, mileSpeeds;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < limitSegmentMiles[i]; j++) {
            mileLimits.push_back(segmentLimits[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < speedSegmentMiles[i]; j++) {
            mileSpeeds.push_back(segmentSpeeds[i]);
        }
    }
    for (int i = 0; i < 100; i++) {
        int speeding = mileSpeeds[i] - mileLimits[i];
        if (speeding > max) {
            max = speeding;
        }
    }
    cout << max;
    return 0;
}
