#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 2e5+5;
const int MOD = 1e9+7;

int n, m1,m2, a[MAXN], b[MAXN], sz[MAXN], in[MAXN], cnt = 1;

bool vis[MAXN];

vector<int> adj[MAXN];

/*
any valid input forms a directed tree
n! permutatons / product of all subtree sizes
*/

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long minv(long long a){
    return binpow(a, MOD-2);
}

void dfs(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child,par);
        sz[node] += sz[child];
    }
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> m1 >> m2;

        for(int i = 1; i <= n; i++){
            in[i] = 0;
            adj[i].clear();
            cnt = 1;
            vis[i] = 0;
        }

        for(int i = 1; i <= m1; i++){
            cin >> a[i];
            if(a[i-1]){
                adj[a[i]].push_back(a[i-1]);
                in[a[i-1]]++;
                vis[a[i-1]]=1;
            }
        }
        for(int i = 1; i <= m2; i++) cin >> b[i];
        for(int i = m2-1; i >= 1; i--){
            if(b[i+1]){
                adj[b[i]].push_back(b[i+1]);
                in[b[i+1]]++;
                vis[b[i+1]] = 1;
            }
        }

        for(int i = 1; i < m1; i++){
            for(int j = a[i]+1; j < a[i+1]; j++){
                adj[a[i]].push_back(j);
                in[j]++;
                vis[j] = 1;
            }
        }

        for(int i = m2; i > 1; i--){
            for(int j = b[i]-1; j > b[i-1]; j--){
                adj[b[i]].push_back(j);
                in[j]++;
                vis[j] = 1;
            }
        }

        for(int i = a[m1]+1; i <= n; i++){
            if(!vis[i]){
                adj[a[m1]].push_back(i);
                in[i]++;
                vis[i] = 1;
            }
        }

        if(a[1] != 1 || b[m2] != n || a[m1] != b[1]){
            cout << "0\n";
            continue;
        }
        
        queue<int> q;

        int rt = -1;
        for(int i = 1; i <= n; i++){
            if(!in[i]){
                rt = i;
                q.push(i);
            }
        }

        while(q.size()){
            int node = q.front();

            q.pop();

            for(int child : adj[node]){
                if(!--in[child]){
                    q.push(child);
                    cnt++;
                }
            }
        }

        if(cnt != n){
            cout << "0\n";
            continue;
        }

        dfs(rt, -1);

  
        long long ans = 1;

        for(int i = 1; i <= n; i++) ans = (ans * i) % MOD;

        long long div = 1;

        for(int i = 1; i <= n; i++) div = (div * sz[i]) % MOD;


        ans = (ans * minv(div));

        cout << ans % MOD << "\n";

        
    }
}