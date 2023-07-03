#include <bits/stdc++.h>
using namespace std;
bool valid(vector<int>& time, int stage, int t){
    priority_queue<int, vector<int>, greater<int>> stage_last_time;
    for(int i = 0; i < stage; i++){
        stage_last_time.push(0);
    }
    //for each time get the earliest last time from stage last time
    for(int v: time){
        int earliest_last_time = stage_last_time.top();
        stage_last_time.pop();
        if(earliest_last_time+v <= t){
            stage_last_time.push(earliest_last_time+v);
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> time(n);
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    int lo = 1, hi = n;
    while(lo < hi){
        int mid = (lo+hi)/2;
        bool successful = valid(time, mid, t);
        if(!successful){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    cout << lo << endl;
}
/*
SAMPLE INPUT:

5 8
4
7
8
6
4
SAMPLE OUTPUT:



4
queue<int> FIFO top() return first element
priority_queue<int> top() return the largest element
priority_queue<int, vector<int>, greater<int>> top() returns the smallest element

*/