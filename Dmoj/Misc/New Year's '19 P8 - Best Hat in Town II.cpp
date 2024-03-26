#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <set>

using namespace std;

const int MAXN = 1e5+5;


int n,m,low[MAXN*5],disc[MAXN*5],cnt,t,sz[MAXN*5],comp[MAXN*5],dp[MAXN*5];
stack<int> st;
bool in[MAXN*5];

//woew unordered set is very bad
vector<int> adjScc[MAXN*5],adj[MAXN*5];

void tarjans(int node){
    low[node] = disc[node] = t++;
    in[node] = 1;
    st.push(node);

    for(int child:adj[node]){
        if(!disc[child]){
            tarjans(child);

            low[node] = min(low[node],low[child]);
        }
        else if(in[child]){
            low[node] = min(low[node],disc[child]);
        }
    }

    if(low[node] == disc[node]){
        while(st.top() != node){
            comp[st.top()] = cnt;
            
            //only add to sz if its an original node
            sz[cnt] += (st.top() <= n);
            in[st.top()] = 0;
            st.pop();
        }

        comp[node] = cnt;
        sz[cnt] += (node <= n);
        in[node] = 0;
        st.pop();

        cnt++;

    }
}

void dfs(int node){

    if(in[node]) return;

    in[node] = 1;

    dp[node] = sz[node];
    int res = 0;
    

    for(int child:adjScc[node]){
        
        dfs(child);
        
        res = max(res,dp[child]);
    }

    dp[node] += res;

    

}

void update(int x, int node, int l, int r, int ln, int rn){
    if(ln > r || rn < l) return;
    if(l >= ln && r <= rn){
        adj[node+n].push_back(x);
        return;
    }
    else{
        int mid = (l+r)>>1;

        update(x,node<<1,l,mid,ln,rn);
        update(x,node<<1|1,mid+1,r,ln,rn);
    }
}


//to connect the original nodes to the ones in the segtree
void update2(int x, int pos, int node, int l, int r){
    if(l > pos || r < pos)  return;

    if(l <= pos && r >= pos){
        adj[x].push_back(node+n);

        if(l == r) return;
    }

    int mid = (l+r)>>1;

    update2(x,pos,node<<1,l,mid);
    update2(x,pos,node<<1|1,mid+1,r);

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;

    

    

    //😭😭😭😭😭😭😭😭
    for(int i = 0; i < m; i++){
        int x,l,r; cin >> x >> l >> r;

        //segtree?


        update(x,1,1,n,l,r);
    }

    for(int i = 1; i <= n; i++) update2(i,i,1,1,n);

    for(int i = 1; i <=5*n; i++){
        if(!disc[i]) tarjans(i);
    }

   

    /*
    
    for(int i = 1; i <= n; i++){
        cout << i << " " << comp[i] << " " << sz[comp[i]] << "\n";
    }
    */



    for(int i = 1; i <= 5*n; i++){
        for(int child:adj[i]){
            if(comp[i] != comp[child]){
                adjScc[comp[i]].push_back(comp[child]);
            }
        }
    }

   
    for(int i = 0; i < cnt; i++){
        sort(adjScc[i].begin(), adjScc[i].end() );
        adjScc[i].erase(unique(adjScc[i].begin(), adjScc[i].end() ), adjScc[i].end());
        in[i] = 0;
    }
    dfs(comp[1]);

    

    cout << dp[comp[1]] << "\n";






}