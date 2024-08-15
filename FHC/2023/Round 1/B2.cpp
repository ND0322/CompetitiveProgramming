#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int ans = 0;

map<int,set<int>> factors;

vector<int> out;

map<pair<int,int>,pair<int,int>> mp;

//use ulimit -s unlimited

int solve(int p, int sm, int d){
    if(p == 1 && sm == 41) return 0;
    if(sm >= 41) return 1e9;

    if(mp.find({p,sm}) != mp.end()) return mp[{p,sm}].first;

    pair<int,int> ans = {1e9, -1};

    if(factors.find(p) == factors.end()){
        for(int i = 1; i * i <= p; i++){
            if(p%i) continue;
            factors[p].insert(i);
            factors[p].insert(p/i);
        }
    }

    for(int i : factors[p]) ans = min(ans, {solve(p/i, sm + i, d+1) + 1, i});
    

    mp[{p,sm}] = ans;
    return ans.first;
}





int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        int p; cin >> p;

        
        int sm = 0;
        int tmp = p;

        for(int i = 2; i * i <= tmp; i++){
            while(tmp%i == 0){
                sm += i;
                tmp /= i;
            }
        }

        if(tmp > 1) sm += tmp;
        

        if(sm > 41){
            cout << "Case #" << _ << ": -1\n";
            continue;
        }

        cout << "Case #" << _ << ": ";

        cout << solve(p, 0, 0) << " ";

        int cur = p;
        sm = 0;

        while(sm != 41){
            cout << mp[{cur,sm}].second << " ";
            int tmp = mp[{cur,sm}].second;
            cur /= tmp;
            sm += tmp;
        }

        cout << "\n";

    }
}
