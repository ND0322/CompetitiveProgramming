#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main(){
    int tt; cin >> tt;

    while(tt--){
        string s; cin >> s;

        set<char> sc;

        int ans = 1;

        for(char c : s){
            sc.insert(c);

            if(sc.size() > 3){
                sc.clear();
                sc.insert(c);
                ans++;
            }
        }

        cout << ans << "\n";
    }
}