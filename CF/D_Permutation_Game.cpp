#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

#define int long long

//simulate first n steps

int n, k, x,y, a[MAXN], p[MAXN];

bool vis[MAXN];
int32_t main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n >> k >> x >> y;

        memset(vis, 0, sizeof(vis));

        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) cin >> a[i];

        
        int best = 0;
        int sm = 0;
        int node = x;
        int tmp = k;

        while(!vis[node] && tmp){
            best = max(best, sm + tmp * a[node]);
            sm += a[node];
            vis[node] = 1;
            node = p[node];
            tmp--;
        }

        memset(vis, 0, sizeof(vis));

        int be = 0;
        sm = 0;
        node = y;
        tmp = k;

        while(!vis[node] && tmp){
            be = max(be, sm + tmp * a[node]);
            sm += a[node];
            vis[node] = 1;
            node = p[node];
            tmp--;
        }

        if(best > be) cout << "Bodya\n";
        else if(best < be) cout << "Sasha\n";
        else cout << "Draw\n";

       
        
        

   


    }
}

