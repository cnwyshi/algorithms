//
// Created by genius on 2/14/22.
//
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int bronzeBefore;
    int bronzeAfter;
    int silverBefore;
    int silverAfter;
    int goldBefore;
    int goldAfter;
    int platinumBefore;
    int platinumAfter;
    cin >> bronzeBefore;
    cin >> bronzeAfter;
    cin >>  silverBefore;
    cin >> silverAfter;
    cin >> goldBefore;
    cin >> goldAfter;
    cin >> platinumBefore;
    cin >> platinumAfter;
    int bronze_to_silver = silverAfter - silverBefore + goldAfter - goldBefore + platinumAfter - platinumBefore;
    int silver_to_gold = goldAfter - goldBefore + platinumAfter - platinumBefore;
    int gold_to_platinum = platinumAfter - platinumBefore;
    cout << bronze_to_silver << endl;
    cout << silver_to_gold << endl;
    cout << gold_to_platinum << endl;
}
