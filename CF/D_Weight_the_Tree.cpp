#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];

int n, deg[MAXN];

bool col[MAXN];


/*
leaves have same weight as parent 

2 coloring 
because it is clear that if a parent is good then the child cant be good 
*/


void dfs(int node, int par){
    for(int child : adj[node]){
        if(child == par) continue;
        col[child] = !col[node];
        dfs(child, node);
    }
}

int main(){
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    if(n == 2){
        cout << "2 2\n";
        cout << "1 1\n";
        return 0;
    }

    dfs(1,-1);
    //let 0 be good


    pair<int,int> f = {0, 0};

    for(int i = 1; i <= n; i++){
        if(!col[i]){
            f.first++;
            f.second += deg[i];
        }
        else f.second++;
    }

    pair<int,int> s = {0, 0};

    for(int i = 1; i <= n; i++){
        if(col[i]){
            s.first++;
            s.second += deg[i];
        }
        else s.second++;
    }


    if(f > s){
        cout << f.first << " " << f.second << "\n";

        for(int i = 1; i <= n; i++) cout << (col[i] ? 1 : deg[i]) << " ";
        cout << "\n";
    }
    else{
        cout << s.first << " " << s.second << "\n";



        
        for(int i = 1; i <= n; i++) cout << (!col[i] ? 1 : deg[i]) << " ";
        cout << "\n";
    }




}