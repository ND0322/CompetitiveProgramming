#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

const int MAXN = 2e5+5;

int n, q;


//for any valid there has to be at least one pair that is undirectional
//for odd check for any pair
//for even check that they share a label

int main(){
    cin >> n >> q;

    set<pair<pair<int,int>,char>> tot;
    set<pair<int,int>> share;
    set<pair<int,int>> no;

    while(q--){
        char op; cin >> op;

        if(op == '+'){
            int x,y; cin >> x >> y;

            char c; cin >> c;

            if(tot.lower_bound({{y,x}, '.'}) != tot.end() && (*tot.lower_bound({{y,x}, '.'})).first.first == y && (*tot.lower_bound({{y,x}, '.'})).first.second == x){ 
                auto it = tot.lower_bound({{y,x}, '.'});
                if((*it).second == c) share.insert({x,y});
                else no.insert({x,y});
            }
            tot.insert({{x,y},c});
            continue;
        }
        if(op == '-'){
            int x,y; cin >> x >> y;

            if(share.find({x,y}) != share.end()) share.erase({x,y});
            if(share.find({y,x}) != share.end()) share.erase({y,x});
            if(no.find({x,y}) != no.end()) no.erase({x,y});
            if(no.find({y,x}) != no.end()) no.erase({y,x});

            tot.erase(tot.lower_bound({{x,y}, '.'}));
            continue;
        }
        int k; cin >> k;

        if(k&1) cout << (((bool)share.size() | (bool)no.size()) ? "YES\n" : "NO\n");
        else cout << ((bool)share.size() ? "YES\n" : "NO\n");
    }
}