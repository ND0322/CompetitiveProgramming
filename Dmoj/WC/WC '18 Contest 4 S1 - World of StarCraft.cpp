#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,q,m, parents[MAXN];

char a[MAXN];

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

    parents[x] = y;
}

int main(){
    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        parents[i] = i;
    }

    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;

        

        if(a[x] == a[y]) uni(x,y);
           
    }

    int cnt = 0;

    while(q--){
        int x,y; cin >> x >> y;

        if(a[x] != a[y]) continue;

        cnt += (find(x) == find(y));
    }

    cout << cnt << "\n";

}

//ac
//8 minutes