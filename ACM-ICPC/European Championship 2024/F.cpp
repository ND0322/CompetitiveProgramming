#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e6+5;

int n, m, last[MAXN], mp[MAXN], depth[MAXN];

pair<int,pair<vector<int>,int>> a[MAXN];

/*
assume there exists no good pairs
we construct a bad tree where parents are supersets of children
disjoint become their own node
contradictions means there is a good pair
*/

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        a[i].first = x;
        a[i].second.second = i;

        for(int j = 1; j <= x; j++){
            int y; cin >> y;

            a[i].second.first.push_back(y);
        }
    }

    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

    for(int i = 1; i <= n; i++) mp[i] = a[i].second.second;

    //1 -> 5 -> 10

    for(int i = 1; i <= n; i++){
        vector<int> b = a[i].second.first;

        bool dis = 1;

        for(int j : b) dis &= (!last[j]);

        if(dis){
            for(int j : b) last[j] = i;
            continue;
            depth[i] = 1;
        }

        dis = 1;

        for(int j : b) dis &= (!last[j] || (last[j] == last[b[0]]));

        if(dis){
            for(int j : b) last[j] = i;
            depth[i] = depth[last[b[0]]] + 1;
            continue;
        }

     
        cout << "YES\n";
        pair<int,int> dep = {-1,-1};
        for(int j : b) dep = max(dep, {depth[last[j]], last[j]});

        cout << mp[dep.second] << " " << mp[i] << "\n";
        return 0;
        
    }

    cout << "NO\n";



    
}