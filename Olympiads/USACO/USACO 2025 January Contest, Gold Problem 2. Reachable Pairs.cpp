#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n,m, parents[MAXN], sz[MAXN], ans;

bool added[MAXN];
string t;

vector<int> adj[MAXN];

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

    ans -= (sz[y] * (sz[y]-1)) / 2;

    parents[y] = x;
    sz[x] += sz[y];
}



/*
dsu

cnt number of removed

operation 1: remove node completely (remove from dsu, subtract from size)
operation 2: keep node, (subtract 1 from size, dont remove from dsu)

10

each edge can get added at most once


reverse operations:
Opt1: insert a node into dsu with all of its original edges and possible dummy node
Opt2: add 1 to component sz

keep all opt2 nodes as dummy nodes in the beginning of the process 

link all type 1 nodes at the start
*/

int main(){
    cin >> n >> m;

    cin >> t;

    for(int i = 1; i <= n; i++) parents[i] = i;

    for(int i = 0; i < n; i++){
        if(t[i] == '1') added[i+1] = 1;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        if(t[x-1] == '1' && t[y-1] == '1'){
            uni(x,y);
            continue;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> b;
    for(int i = n-1; i >= 0; i--){
        if(t[i] == '0'){
            for(int child : adj[i+1]){
                if(added[child]) uni(i+1, child);
            }

            sz[find(i+1)]++;
            added[i+1] = 1;
            

            ans += (sz[find(i+1)] * (sz[find(i+1)]-1)) / 2;
        }
        else{
           
            ans -= (sz[find(i+1)] * (sz[find(i+1)]-1)) / 2;
            sz[find(i+1)]++;
            ans += (sz[find(i+1)] * (sz[find(i+1)]-1)) / 2;
            

            //subtract and add new contribution
        }

        b.push_back(ans);

    }

    

    reverse(b.begin(), b.end());

    for(int i : b) cout << i << "\n";
}

/*

*/ 