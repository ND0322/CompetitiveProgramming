#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
BB
..

is fine

B.
.B

must be seperated by some B
                          B

odd if ends are opposite, even otherwise 
*/


int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        string s; cin >> s;
        string t; cin >> t;

        s = '.' + s;
        t = '.' + t;

        bool flag = 1;

        int i = 1;

        vector<pair<int,int>> ones;

        for(int i = 1; i <= n; i++){
            if(s[i] == 'B' && t[i] == 'B') continue;

            if(s[i] == 'B') ones.push_back({i,0});
            else ones.push_back({i, 1});
        }

        for(int i = 0; i < (int)ones.size()-1; i++){
            if(ones[i].second == ones[i+1].second) flag &= ((ones[i+1].first - ones[i].first) % 2);
            else flag &= !((ones[i+1].first - ones[i].first) % 2);
        }

        cout << (flag ? "YES\n" : "NO\n");


    }
}