#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

//we will get the center of the path between two nodes
//if we keep on querying the right and left seperately after rerooting it takes log2 guesses 

int par[MAXN];
bool marked[MAXN], vis[MAXN][MAXN];

int query(int x, int y){
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void dac(int x, int y){
    if(x > y) swap(x,y);
    if(vis[x][y]) return;
    vis[x][y] = 1;
    int mid = query(x,y);

    if(mid == x || mid == y){
        if(par[x] && !par[y]){
            par[y] = x;
            return;
        }
        if(par[y] && !par[x]){
            par[x] = y;
            return;
        }
        if(!par[x] && !par[y]){
            par[x] = y;
            return;
        }        
    }

    

    dac(x, mid);
    dac(y, mid);

}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            par[i] = 0;
            marked[i] = 0;
        }

        for(int i = 2; i <= n; i++){
            if(par[i]) continue;

            dac(1,i);
        }

        for(int i = 1; i <= n; i++) cout << par[i] << " ";
        cout << "\n";

        cout << "! ";
        for(int i = 1; i <= n; i++){
            if(par[i]) cout << i << " " << par[i] << " ";
        }

        cout << "\n";

        cout.flush();

       
    }
}