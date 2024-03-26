#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int MAXN = 4e6+5;

int n, st[MAXN<<1];

vector<pair<pair<int, int>,pair<int,int>>> inp;

vector<pair<int,pair<int,int>>> l[MAXN];

//x, type (0 for add 1 for remove 2 for vert), y1, y2

map<int,int> coord;
//compress y

set<int> e;

void update(int i, int x){
    for(st[i+=n] += x; i > 1; i>>=1) st[i>>1] = st[i] + st[i^1];
}

int query(int l, int r){
    int ans = 0;
    for(l+=n,r+=n; l < r; l>>=1, r>>=1){
        if(l&1) ans += st[l++];
        if(r&1) ans += st[--r];
    }
    return ans;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        inp.push_back({{x1,x2},{y1,y2}});

        e.insert(y1);
        e.insert(y2);
        e.insert(x1);
        e.insert(x2);

        
    }
    
    int cnt = 1;

    for(int i : e) coord[i] = cnt++;

    

    
    for(int i = 0; i < n; i++){
        auto [x1,x2] = inp[i].first;
        auto [y1,y2] = inp[i].second;

        x1 = coord[x1];
        x2 = coord[x2];
        y1 = coord[y1];
        y2 = coord[y2];

        if(x1 == x2) l[x1].push_back({1,{y1,y2}});
        else{
            l[x1].push_back({0,{y1,y2}});
            l[x2+1].push_back({2, {y1,y2}});
            //y1 will equal y2
        }
    }

    

    long long ans = 0;

    for(int i = 0; i <= 4e6; i++){
        sort(l[i].begin(), l[i].end());
        
        for(auto [t, y] : l[i]){
            if(!t) update(y.first, 1);
            if(t == 1) update(y.first,-1);
            if(t == 2) ans += query(y.first, y.second+1);
        }
    }

    cout << ans << "\n";

    

    
   




}