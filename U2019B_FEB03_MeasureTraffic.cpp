#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main_measuer_traffic() {
//int main() {
    ifstream ifs("traffic.in");
    ofstream ofs("traffic.out");
    int n, low, high, lowest = -100000, highest = 100000;
    ifs >> n;
    vector<string> ramps;
    vector<int> lows, highs;
    for (int i = 0; i < n; i++) {
        string ramp;
        ifs >> ramp >> low >> high;
        ramps.push_back(ramp);
        lows.push_back(low);
        highs.push_back(high);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (ramps[i] == "none") {
            lowest = max(lowest, lows[i]);
            highest = min(highest, highs[i]);
        } else if (ramps[i] == "on") {
            lowest -= highs[i];
            highest -= lows[i];
            lowest = max(lowest, 0);
        } else if (ramps[i] == "off") {
            lowest += lows[i];
            highest += highs[i];
        }
    }
    ofs << lowest << " " << highest << endl;

    lowest = -100000;
    highest = 100000;
    for (int i = 0; i < n; i++) {
        if (ramps[i] == "none") {
            lowest = max(lowest, lows[i]);
            highest = min(highest, highs[i]);
        } else if (ramps[i] == "on") {
            lowest += lows[i];
            highest += highs[i];
        } else if (ramps[i] == "off") {
            lowest -= highs[i];
            highest -= lows[i];
            lowest = max(lowest, 0);
        }
    }
    ofs << lowest << " " << highest << endl;

    return 0;
}

/*
      segmentMiles2;
 speedSegmentMiles

 add/modify/delete: 7

 s     egmentMiles2;
 speedSegmentMiles

 add/modify/delete: 6, smart way

 LCS
 Longest Common Sequence

 */