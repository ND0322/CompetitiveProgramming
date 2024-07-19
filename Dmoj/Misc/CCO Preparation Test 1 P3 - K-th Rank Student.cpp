#include <bits/stdc++.h>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

const int MAXN = 1e5+5;

int n,m,q, parents[MAXN];

ost sets[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    parents[y] = x;
    if(sets[y].size() > sets[x].size()) sets[x].swap(sets[y]);
    for(pair<int,int> i : sets[y]) sets[x].insert(i);
}

int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;

        parents[i] = i;
        sets[i].insert({x,i});
    }

    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        uni(x,y);
    }

    cin >> q;
    while(q--){
        char c; cin >> c;

        if(c == 'B'){
            int x,y; cin >> x >> y;

            uni(x,y);
        }

        else{
            int x,k; cin >> x >> k;

            if(sets[find(x)].size() < k){
                cout << "-1\n";
                continue;
            }

            cout << (*sets[find(x)].find_by_order(k-1)).second << "\n";
        }
    }
}



