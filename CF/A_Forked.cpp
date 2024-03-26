#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main(){
    int tt; cin >> tt;

    while(tt--){
        int a,b; cin >> a >> b;

        int x1,y1; cin >> x1 >> y1;

        //can only be forked from 8 directions

        int x2, y2; cin >> x2 >> y2;

        vector<pair<int,int>> stuffs;

        stuffs.push_back({x1-a,y1-b});
        stuffs.push_back({x1+a,y1-b});
        stuffs.push_back({x1-a,y1+b});
        stuffs.push_back({x1+a,y1+b});
        stuffs.push_back({x1-b,y1-a});
        stuffs.push_back({x1+b,y1-a});
        stuffs.push_back({x1-b,y1+a});
        stuffs.push_back({x1+b,y1+a});

        sort(stuffs.begin(), stuffs.end() );
        stuffs.erase(unique(stuffs.begin(), stuffs.end() ), stuffs.end());

        int ans = 0;

        for(pair<int,int> p : stuffs){
            if(p.first - a == x2 && p.second - b == y2){
                ans++;
                continue;
            }
            if(p.first - a == x2 && p.second + b == y2){
                ans++;
                continue;
            }
            if(p.first + a == x2 && p.second - b == y2){
                ans++;
                continue;
            }
            if(p.first + a == x2 && p.second + b == y2){
                ans++;
                continue;
            }
            if(p.first - b == x2 && p.second - a == y2){
                ans++;
                continue;
            }
            if(p.first + b == x2 && p.second - a == y2){
                ans++;
                continue;
            }
            if(p.first - b == x2 && p.second + a == y2){
                ans++;
                continue;
            }
            if(p.first + b == x2 && p.second + a == y2){
                ans++;
                continue;
            }
        }
        
        cout << ans << "\n";

    }
}