#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

//compress cycles
//its functional so theres an easier way but im lazy so tarjans W

//i want to use sets and copying so mayb ill abuse python

const int MAXN = 3e5+5;

int r,c,n, low[MAXN], disc[MAXN], comp[MAXN], cnt, t, nxt[MAXN], ans;

vector<int> di = {1,0,-1,0};
vector<int> dj = {0,1,0,-1};

vector<int> adj[MAXN];

set<int> a[MAXN], b[MAXN], cur;

bool in[MAXN], sz[MAXN];

stack<int> st;

char grid[505][505];



void tarjans(int node){
    low[node] = disc[node] = ++t;

    in[node] = 1;
    st.push(node);

    if(nxt[node] != -1){
        if(!disc[nxt[node]]){
            tarjans(nxt[node]);

            low[node] = min(low[node], low[nxt[node]]);
        }
        else if(in[nxt[node]]) low[node] = min(low[node], disc[nxt[node]]);
    }
    

    if(low[node] == disc[node]){
        while(st.top() != node){
            //cout << cnt << " " << st.top() << "\n";
            in[st.top()] = 0;
            comp[st.top()] = cnt;
            
            for(int i : b[st.top()]) a[cnt].insert(i);
            sz[cnt] = 1;
            st.pop();

        }

        //cout << cnt << " " << st.top() << "\n";

        in[node] = 0;
        comp[node] = cnt;

        for(int i : b[node]) a[cnt].insert(i);

        st.pop();

        cnt++;
    }
    

}

//dont need to add or erase from set if the dude is already in there

void dfs(int node){
    //cout << node << "\n";
    vector<int> del;

    for(int i : a[node]){
        if(cur.find(i) == cur.end()){
            cur.insert(i);
            del.push_back(i);
        }
    }
    
    ans = max(ans, (int)cur.size());



    for(int child : adj[node]) dfs(child);

    for(int i : del) cur.erase(i);


}




int main(){
    cin >> r >> c;


    n = r*c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> grid[i][j];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            nxt[i*c+j] = -1;
            comp[i*c+j] = -1;
            if(grid[i][j] == '.' || grid[i][j] == '#') continue;

            

            for(int k = 0; k < 4; k++){
                if(i+di[k] >= 0 && i+di[k] < r && j+dj[k] >= 0 && j+dj[k] < c && grid[i+di[k]][j+dj[k]] == '#') b[i*c+j].insert((i+di[k])*c + j + dj[k]);
            }

            if(grid[i][j] == '<' && j > 0 && grid[i][j-1] != '.' && grid[i][j-1] != '#') nxt[i*c+j] = i * c + j-1;
            if(grid[i][j] == '>' && j < c-1 && grid[i][j+1] != '.' && grid[i][j+1] != '#') nxt[i*c+j] = i*c + j+1;
            if(grid[i][j] == '^' && i > 0 && grid[i-1][j] != '.' && grid[i-1][j] != '#') nxt[i*c+j] = (i-1) * c + j;
            if(grid[i][j] == 'v' && i < r-1 && grid[i+1][j] != '.' && grid[i+1][j] != '#') nxt[i*c+j] = (i+1) * c + j; 
        }
    }

   

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] != '.' && grid[i][j] != '#' && !disc[i*c+j]) tarjans(i*c+j);
        }
    }

    fill(in,in+n, 1);

    for(int i = 0; i < n; i++){
        if(nxt[i] != -1 && comp[nxt[i]] != comp[i]){
            adj[comp[nxt[i]]].push_back(comp[i]);
            in[comp[i]] = 0;
        }
    }

   //for(int i = 0; i < r; i++){
        //for(int j = 0; j < c; j++) cout << comp[i*c+j] << " ";
        //cout << "\n";
    //}

    for(int i = 0; i < cnt; i++){
        if(in[i] || sz[i]) dfs(i);
    }

    cout << ans << "\n";

}