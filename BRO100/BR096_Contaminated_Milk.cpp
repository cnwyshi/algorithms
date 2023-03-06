#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <bitset>

using namespace std;
bool less_than(vector<int> a, vector<int> b){
    return a [2] < b[2];
}
int main() {
    size_t n, m, d, s;
    cin >> n >> m >> d >> s;
    vector<vector<int>> drinks;
    map<int, set<int >> milk_to_people;
    for (int i = 0; i < d; i++) {
        int person, milk, time;
        cin >> person >> milk >> time;
        drinks.push_back({person, milk, time});
        milk_to_people[milk].insert(person);
    }
    vector<vector<int>> sicks;
    for (int i = 0; i < s; i++) {
        int person, time;
        cin >> person >> time;
        sicks.push_back({person, time});
    }
    sort(drinks.begin(), drinks.end(), less_than);
    bitset<51> possible_bad_milks;
    possible_bad_milks.set();
    for (int i = 0; i < s; i++) {
        int sick_person = sicks[i][0];
        int sick_time = sicks[i][1];
        bitset<51> current_bad_milks;
        for (int j = 0; j < d && drinks [j][2] < sick_time; j++) {
            int drink_person = drinks[j][0];
            int drink_milk = drinks[j][1];
            int drink_time = drinks[j][2];
            if (drink_person == sick_person) {
                current_bad_milks[drink_milk] = 1;
            }
        }
        possible_bad_milks = possible_bad_milks & current_bad_milks;
    }
    size_t ans = 0;
    for (int i = 1; i <= m; i++) {
        if (possible_bad_milks[i] == 1) {
            ans = max(ans, milk_to_people[i].size());
        }
    }
    cout << ans;
    return 0;
}