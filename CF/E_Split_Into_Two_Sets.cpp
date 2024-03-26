#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 2e5+5;

int n, parents[MAXN], sz[MAXN], deg[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

void uni(int x, int y){
    x = find(x);
    y = find(y);


    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);

    parents[y] = x;
    sz[x] += sz[y];
}

int main(){
    int tt; cin >> tt;

    while(tt--){
        cin >> n;

        //1 - 2
        //| /
        //3 


        //4 - 8
        

        //6 - 1

        //2 - 5
        //|
        //3 - 7

        bool flag = 1;
    
        for(int i = 1; i <= n; i++){
            parents[i] = i;
            sz[i] = 1;
            deg[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            int x,y; cin >> x >> y;

            deg[x]++;
            deg[y]++;

            
            if(x == y || deg[x] > 2 || deg[y] > 2) flag = 0;
            uni(x,y);
        }

        if(!flag){
            cout << "NO\n";
            continue;
        }

        flag = 1;

        for(int i = 1; i <= n; i++){
            if(sz[find(i)] & 1){
                flag = 0;
                cout << "NO\n";
                break;
            }
        }

        if(flag) cout << "YES\n";
    }
}

