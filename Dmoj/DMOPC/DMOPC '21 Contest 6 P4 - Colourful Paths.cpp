#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;


const int MAXN = 2e5+5;

int n, m,a,b,c,d, ans[MAXN];

vector<pair<int,int>> adj[MAXN];
pair<int,int> rebuild[MAXN];

bool visited[MAXN];

bool dfs(int node, int bad){
    if(node == a) fill(visited+1, visited+n+1, 0);
    visited[node] = 1;
    if(node == b) return 1;

    for(pair<int,int> c:adj[node]){
        if(c.first == bad || visited[c.first]) continue;
        if(dfs(c.first, bad)) return 1;
    }
    return 0;
}

void dfs2(int node){
    if(node == a) return;
    ans[rebuild[node].second] = 1;
    dfs2(rebuild[node].first);
   
}

//obviously use only 2 colours
//if d or c lie on all paths between a and b no answer
//if less than 2 edges between b d no answer

int main(){
    cin >> n >> m;

    

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
        ans[i] = -1;
    }

    cin >> a >> b >> c >> d;
    //input is so goddamn annoying

    for(pair<int,int> p : adj[c]){
        if(p.first == d){
            cout << "-1\n";
            return 0;
        }
    }

    for(pair<int,int> p : adj[d]){
        if(p.first == c){
            cout << "-1\n";
            return 0;
        }
    }

    if(!dfs(a,c) && !dfs(a,d)){
        cout << "-1\n";
        return 0;
    }

    int bad = 0;

    if(!dfs(a,d)) bad = c;
    else{
        if(!dfs(a,c)) bad = d;
        else bad = c;
    }

    memset(visited, 0, sizeof(visited));
    queue<int> q;

    q.push(a);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == b) break;

        for(pair<int,int> p : adj[node]){
            if(visited[p.first] || p.first == bad) continue;
            visited[p.first] = 1;
            q.push(p.first);

            rebuild[p.first] = {node,p.second};
        }
    }
    dfs2(b);

    queue<pair<int,int>> qq;
    memset(visited, 0, sizeof(visited));

    qq.push({bad,1});

    while(!qq.empty()){
        int node = qq.front().first;
        int last = qq.front().second;

        qq.pop();

        for(pair<int,int> p : adj[node]){
            if(ans[p.second] == -1){
                if(last == 1) ans[p.second] = 2;
                else ans[p.second] = 1;
            }

            if(!visited[p.first]){
                visited[p.first] = 1;
                qq.push({p.first, ans[p.second]});
            }
        }
    }

    cout << 2 << "\n";
    for(int i = 0; i < m; i++) cout << ans[i] << "\n";




}