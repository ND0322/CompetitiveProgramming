#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    //aproach: count number of distinct letters on each side. If there is more than one, print yes

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        set<char> l;


        for(int i = 0; i < s.size()/2;i++){
            l.insert(s[i]);

        }

        if(l.size() > 1){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO\n";
        }

    }
}