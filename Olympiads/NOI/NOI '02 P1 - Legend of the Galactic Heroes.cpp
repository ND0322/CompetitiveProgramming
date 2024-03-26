#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 3e4+5;

int q, parents[MAXN], sz[MAXN], dist[MAXN];

int find(int x){
    if(x == parents[x]) return x;

    int nxt = find(parents[x]);
    dist[x] += dist[parents[x]];
    return parents[x] = nxt;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;


    parents[x] = y;
    dist[x] = sz[y];
    sz[y] += sz[x];
}



int main(){
    cin.tie(NULL) -> ios_base::sync_with_stdio(0);
    cin >> q;

    for(int i = 0; i < MAXN; i++){
        parents[i] = i;
        sz[i]=  1;
    }

    while(q--){
        char c; cin >> c;

        if(c == 'M'){
            int x,y; cin >> x >> y;

            uni(y,x);   
        }
        else{
            int x, y; cin >> x >> y;

            if(find(x) != find(y)){
                cout << "-1\n";
                continue;
            }

            cout << max(0,abs(dist[x] - dist[y]) - 1) << "\n";
            
        }
    }
    
   
}


