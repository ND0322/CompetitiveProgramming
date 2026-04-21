#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m, k, deg[MAXN]; 

bool vis[MAXN];

map<string,int> patterns;
vector<int> adj[MAXN];



int main(){
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        string s; cin >> s;

        patterns[s] = i;
    }


    int cnt = 0;

    for(int i = 1; i <= m; i++){
        //place some number of _

        string t; cin >> t;

        int ind; cin >> ind;
        
        vector<int> nxt;

        for(int l = 0; l < (1<<k); l++){
            string s = "";
            for(int p = 0; p < k; p++){
                if(l & (1<<p)) s += '_';
                else s += t[p];
            }

            if(patterns.find(s) != patterns.end()) nxt.push_back(patterns[s]);
        }

        for(int j : nxt){
            if(ind == j){
                cnt++;
                continue;
            }
            adj[ind].push_back(j);
            deg[j]++;
        }
    }

    if(cnt != m){
        cout << "NO\n";
        return 0;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!deg[i]){
            q.push(i);
            vis[i] = 1;
        }
    }

    vector<int> ans;

    while(q.size()){
        int node = q.front();

        ans.push_back(node);

        q.pop();

        for(int child : adj[node]){
            if(vis[child]) continue;
            deg[child]--;
            if(!deg[child]) q.push(child);
        }
    }

    if(ans.size() != n) cout << "NO\n";
    else{
        cout << "YES\n";

        for(int i : ans) cout << i << " ";
        cout << "\n";
    }



}

/*
for each string we know the set of patterns it matches to
this set is at most 2^k length
*/

