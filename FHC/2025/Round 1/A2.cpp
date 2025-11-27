#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//use ulimit -s unlimited


//or just mst 
const int MAXN = 5e5+5;

int n, a[MAXN];

bool vis[MAXN];


bool f(int x){
    queue<int> q;

    for(int i = 1; i <= n; i++) vis[i] = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] <= x){
            vis[i] = 1;
            q.push(i);
        }
    }

    while(q.size()){
        int node = q.front();

        q.pop();

        if(node < n && abs(a[node+1] - a[node]) <= x && !vis[node+1]){
            vis[node+1] = 1;
            q.push(node+1);
        }

        if(node > 1 && abs(a[node-1] - a[node]) <= x && !vis[node-1]){
            vis[node-1] = 1;
            q.push(node-1);
        }
    }

    bool flag = 1;

    for(int i = 1; i <= n; i++)  flag &= vis[i];
    return flag;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int tt; cin >> tt;

    for(int _ = 1; _ <= tt; _++){

        cin >> n;

        for(int i = 1; i <= n; i++) cin >> a[i];

        int lo = 0;
        int hi = 1e9;

        int ans = 1e9;

        while(lo <= hi){
            int mid = (lo+hi)>>1;

            if(f(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        cout << "Case #" << _ << ": " << ans << "\n";
        

        
    }
}