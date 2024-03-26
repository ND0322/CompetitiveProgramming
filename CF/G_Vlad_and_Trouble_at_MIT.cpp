#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, a[MAXN], ans;

bool has[MAXN][2];



string s;

vector<int> adj[MAXN];

void dfs(int node, int par){
    if(s[node] == 'P') has[node][0]=1;
    if(s[node]=='S') has[node][1] = 1;

    int cnta = has[node][0];
    int cntb = has[node][1];

    for(int child : adj[node]){
        if(child == par) continue;

        dfs(child, node);

        if(s[node] == 'P' && has[child][1]) ans++;
        if(s[node] == 'S' && has[child][0]) ans++;
        cnta += has[child][0];
        cntb += has[child][1];
    }

    if(s[node] == 'C'){
        ans += min(cnta,cntb);

        if(cnta > cntb) has[node][0] = 1;
        if(cnta < cntb) has[node][1] = 1;
    }


}


int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        ans = 0;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            has[i][0] = has[i][1] = 0;
        }
        s = 'S';

        for(int i = 2; i <= n; i++){
            int x; cin >>x;

            
            adj[x].push_back(i);
            adj[i].push_back(x);
        }

        string t; cin >> t;

        s += t;

        dfs(1,-1);

        cout << ans << "\n";
        

    }
}
