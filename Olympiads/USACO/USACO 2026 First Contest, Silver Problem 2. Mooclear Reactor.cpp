#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;



int n,m, l[MAXN], r[MAXN], k[MAXN], val[MAXN], col[MAXN], ans = 0;

vector<pair<int,int>> adj[MAXN];

vector<int> comp;
bool flag = 0, vis[MAXN];
/*
if we can't 2 color

c - b + a - x = x

x is fixed 


if 2 colorable 

try both 2 colorings 

dfs to calculate the edge sums which gives us the ranges that x can be in for each node
find the x that maximizes number of ranges 
*/


bool color(int node, int par, bool c, int sm){
    if(vis[node]) return 0;
    if(col[node]){
        if(col[node] != c+1){
            flag |= (sm & 1);
            val[node] = sm/2;
            return 0;
        }
        
        if(sm != k[node]) flag = 1;
        return 1;
    }
   
    comp.push_back(node);
    col[node] = c+1;
    k[node] = sm;
    bool ret = 1;
    for(auto [child, weight] : adj[node]){
        if(child == par) continue;
        if(!color(child,node, !c, weight - sm)) ret = 0;
    }
    return 1;
}

void dfs(int node){
    vis[node] = 1;
    
    for(auto [child, weight] : adj[node]){
        if(vis[child]) continue;
        if(val[child] != 2e9 && val[child] != weight - val[node]){
            flag = 1;
            return;
        }

        val[child] = weight - val[node];
        dfs(child);
    }

    if(val[node] >= l[node] && val[node] <= r[node]) ans++;
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m;

        for(int i = 1; i <= n; i++) cin >> l[i];
        for(int i = 1; i <= n; i++) cin >> r[i];

        flag = 0;
        ans = 0;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            col[i] = 0;
            val[i] = 2e9;
            vis[i] = 0;
        }

        for(int i = 1; i <= m; i++){
            int x,y,c; cin >> x >> y >> c;

            if(x == y){
                if(val[x] != 2e9 && val[x] != c/2 || (c&1)) flag = 1;
                val[x] = c/2;
                continue;
            }

            adj[x].push_back({y,c});
            adj[y].push_back({x,c});
        }

        for(int i = 1; i <= n; i++){
            if(val[i] == 2e9) continue;
            dfs(i);
        }

        
        //l = c - x, x = c-l


        for(int i = 1; i <= n; i++){
            if(vis[i] || col[i]) continue;
            comp.clear();
            if(!color(i, -1, 0, 0)) dfs(i);
            else{
                vector<pair<int,int>> events;

    
                for(int i : comp){

                    int ll = (l[i] - k[i]) * pow(-1, col[i]-1);
                    int rr = (r[i] - k[i]) * pow(-1, col[i]-1);
                    cout << ll << " " << rr << "\n";
                    events.push_back({min(ll, rr), 0});
                    events.push_back({max(ll,rr), 1});
                }
                sort(events.begin(), events.end());


                int best =0;
                int cur = 0;

                for(auto [fuck, you] : events){
                    if(!you) cur++;
                    best = max(best, cur);
                    if(you) cur--;
                }

                ans += best;



                
            }

            
        }


        if(flag){
            cout << "-1\n";
            continue;
        }

        cout << ans << "\n";









    }
}