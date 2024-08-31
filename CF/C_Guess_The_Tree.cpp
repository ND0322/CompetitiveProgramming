#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1005;

//we will get the center of the path between two nodes
//if we keep on querying the right and left seperately after rerooting it takes log2 guesses 

int par[MAXN];
bool marked[MAXN];

int query(int x, int y){
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void dac(int x, int y){
    int mid = query(x,y);
    if(mid == x || mid == y){
        par[y] = x;
        marked[y] = 1;
        return;
    }

    if(!marked[x]) dac(x, mid);
    dac(mid, y);



}

int main(){
    int tt; cin >> tt;

    while(tt--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++){
            par[i] = 0;
            marked[i] = 0;
        }

        marked[1] = 1;

        for(int i = 2; i <= n; i++){
            if(marked[i]) continue;
            dac(1,i);
            marked[i] = 1;
        }

        cout << "! ";
        for(int i = 2; i <= n; i++){
            cout << i << " " << par[i] << " ";
        }

        cout << "\n";

        cout.flush();

       
    }
}