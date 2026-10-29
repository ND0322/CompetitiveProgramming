#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;

        s = "." + s;

        map<string, set<int>> mp;

        for(int i = 1; i < n; i++) mp[s.substr(i,2)].insert(i);

        bool flag = 0;

        for(auto [a, b] : mp){
            if(b.size() < 2) continue;
            if(b.size() > 2){
                flag = 1;
                continue;
            }
            if(*b.rbegin() != *b.begin()+1) flag = 1;
        }

        cout <<(flag ? "YES\n" : "NO\n");

        
    }
}