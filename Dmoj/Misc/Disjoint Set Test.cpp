#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5+5;

int n,m, parents[MAXN];

int find(int x){
    while(x != parents[x]){
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

bool uni(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return 0;
    parents[x] = y;
    return 1;
}


int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) parents[i] = i;
    if(m < n-1){
        cout << "Disconnected Graph\n";
        return 0;
    }
    for(int i = 1; i <= m; i++){
        int x,y; cin >> x >> y;

        if(uni(x,y)) cout << i << "\n";
    }

}