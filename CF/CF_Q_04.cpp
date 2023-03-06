//
// Created by genius on 12/26/2022.
//
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
int t,n;
void check(){
    cin>>n;
    string k;
    cin>>k;
    for (int i=0;i<n-1;i++){
        string nk=k;
        string sub;
        sub.push_back(k[i]);
        sub.push_back(k[i+1]);
        for (int j=0;j<2;j++){
            string::size_type m = nk.find(sub);
            if (m != string::npos)
                nk.replace(m, 2, "11");
        }
        for (int j=0;j<2;j++){
            string::size_type m = nk.find("11");
            if (m != string::npos)
                nk.erase(m, 2);
        }
        if (nk.size()<n-2){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main() {
    cin>>t;
    for (int i=0;i<t;i++){
        check();
    }
}

