#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//for some node meet at the lca of all farthest nodes from this 
//for 10 points we can meet at the centroid
//sqrt batching?
//use centroid for bois further than like root n and use some other meeting point for less than that
//have nodes at higher depths wait for depth[a] - deepest subtree node before moving towards centroid

/*
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9

centroid is 5 

imagine the thing is in 1 and 3
we want to meet up first at 2 which is 1 and 3 centroid before moving again

        5
       / \
      4   6
      |   |
      3   7
      |   |
      2   8
      |   |
      1   9



        1
       / \
      2   3
     / \ / \
    4  56   7

centroid again rooted at 6

root at center of tree
alterate binary steps 
*/

const int MAXN = 105;

int n, sz[MAXN], depth[MAXN];
bool marked[MAXN];
vector<int> path[MAXN];
vector<int> adj[MAXN], centroids;

void init(int node, int par){
    sz[node] = 1;

    for(int child : adj[node]){
        if(child == par || marked[child]) continue;
        depth[child] = depth[node]+1;
        init(child, node);
        sz[node] += sz[child];
    }
}

int centroid(int node, int par, int sub){
    for(int child : adj[node]){
        if(child == par || marked[child]) continue;
        if(sz[child] * 2 > sub) return centroid(child, node, sub);
    }
    return node;
}

void decomp(int node, int par, int d){
    if(d >= 2) return;
    init(node, par);
    int rt = centroid(node, par, sz[node]);
    marked[rt] = 1;
    centroids.push_back(rt);

    for(int child : adj[rt]){
        if(marked[child]) continue;
        decomp(child, rt, d+1);
    }
}





int main(){
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int x,y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    decomp(1,-1,0);

    for(int i : centroids) cout << i  << " ";
    cout << "\n";

    





}