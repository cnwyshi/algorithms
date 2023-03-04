#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    string start, target, word;
    cin >> start >> target;
    int n;
    cin >> n;
    set<string> dict;
    for(int i = 0; i < n; i++){
        cin >> word;
        dict.insert(word);
    }
    if(dict.find(target) == dict.end()){
        cout << -1 << endl;
        return 0;
    }
    queue<string> q1, q2;
    q1.push(start);
    q2.push(target);
    map<string, int> front, back;
    front[start] = 0;
    back[target] = 0;
    while(!q1.empty() && !q2.empty()){
        string s = q1.front();
        q1.pop();
        if(back.find(s) != back.end()){
            cout << front[s]+back[s] << endl;
            return 0;
        }
        for(int i = 0; i < s.size(); i++){
            for(char c = 'a'; c < 'z'; c++){
                string t = s;
                t[i] = c;
                if(front.find(t) == front.end() && dict.find(t) != dict.end()){
                    q1.push(t);
                    front[t] = front[s]+1;
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            string t = s.substr(0, i)+s.substr(i+1, s.size()-i-1);
            if(front.find(t) == front.end() && dict.find(t) != dict.end()){
                q1.push(t);
                front[t] = front[s]+1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            for(char c = 'a'; c < 'z'; c++){
                string t = s.substr(0, i) + c + s.substr(i+1, s.size() - i + 1);
                if(front.find(t) == front.end() && dict.find(t) != dict.end()){
                    q1.push(t);
                    front[t] = front[s]+1;
                }
            }
        }
        s = q2.front();
        q2.pop();
        if(front.find(s) != front.end()){
            cout << front[s]+back[s] << endl;
            return 0;
        }
        for(int i = 0; i < s.size(); i++){
            for(char c = 'a'; c < 'z'; c++){
                string t = s;
                t[i] = c;
                if(back.find(t) == back.end() && dict.find(t)!= dict.end()){
                    q2.push(t);
                    back[t] = back[s]+1;
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            string t = s.substr(0, i)+s.substr(i+1, s.size()-i-1);
            if(back.find(t) == back.end() && dict.find(t) != dict.end()){
                q2.push(t);
                back[t] = back[s]+1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            for(char c = 'a'; c < 'z'; c++){
                string t = s.substr(0, i) + c + s.substr(i+1, s.size() - i + 1);
                if(back.find(t) == back.end() && dict.find(t) != dict.end()){
                    q2.push(t);
                    back[t] = back[s]+1;
                }
            }
        }
    }
    cout << -1 << endl;
}
/*
hello
world
6
hello
hollo
worls
wollo
wolld
world

wa
aa front[aa] = 1
ab back[ab] = 1
bb

01234
hello
heollo

s.substr(0, i)
s.substr(i+1, s.size()-i-1)
5*25

helo
*/